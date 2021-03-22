/*

WARNING:
This code doesn't solve the problem below correctly. 
I believe I managed to find a solution later, but I don't think I have the code that actually works. :(

The 15-puzzle has been around for over 100 years; even if you don’t know it by that name, you’ve seen
it. It is constructed with 15 sliding tiles, each with a number from 1 to 15 on it, and all packed into a
4 by 4 frame with one tile missing. Let’s call the missing tile ‘x’; the object of the puzzle is to arrange
the tiles so that they are ordered as:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 x
where the only legal operation is to exchange ‘x’ with one of the tiles with which it shares an edge. As
an example, the following sequence of moves solves a slightly scrambled puzzle:
1 2 3 4 1 2 3 4 1 2 3 4 1 2 3 4
5 6 7 8 5 6 7 8 5 6 7 8 5 6 7 8
9 x 10 12 9 10 x 12 9 10 11 12 9 10 11 12
13 14 11 15 13 14 11 15 13 14 x 15 13 14 15 x
r-> d-> r->
The letters in the previous row indicate which neighbor of the ‘x’ tile is swapped with the ‘x’ tile
at each step; legal values are ‘r’,‘l’,‘u’ and ‘d’, for right, left, up, and down, respectively.
Not all puzzles can be solved; in 1870, a man named Sam Loyd was famous for distributing an
unsolvable version of the puzzle, and frustrating many people. In fact, all you have to do to make a
regular puzzle into an unsolvable one is to swap two tiles (not counting the missing ‘x’ tile, of course).
In this problem, you will write a program for solving the less well-known 8-puzzle, composed of tiles
on a three by three arrangement.

Input:
The first line of the input is an integer N, then a blank line followed by N datasets. There is a blank
line between datasets.
In each dataset, you will receive a description of a configuration of the 8 puzzle. The description is
just a list of the tiles in their initial positions, with the rows listed from top to bottom, and the tiles
listed from left to right within a row, where the tiles are represented by numbers ‘1’ to ‘8’, plus ‘x’.
For example, this puzzle
1 2 3
x 4 6
7 5 8
is described by this list:
1 2 3 x 4 6 7 5 8

Output:
For each dataset, you will print to standard output either the word ‘unsolvable’, if the puzzle has no
solution, or a string consisting entirely of the letters ‘r’, ‘l’, ‘u’ and ‘d’ that describes a series of moves
that produce a solution. The string should include no spaces and start at the beginning of the line.
Print a blank line between datasets.

Sample Input:
1
2 3 4 1 5 x 7 6 8

Sample Output:
ullddrurdllurdruldr

*/

#include <iostream>
#include <math.h>
#include <set>

using namespace std;

set<int> combs;

int table[3][3];

char moves[362880];
int moves_made = 0;

bool solved;

int x;
int y;

void print_table() {

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
                cout << table[i][j] << ' ';
        }
        cout << endl;
    }

    cout << "=====\n";

}

void read_table() {

    char c;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> c;
            if(c == 'x')
                table[i][j] = 0;
            else
                table[i][j] = c - '0';
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {

            if(table[i][j] == 0) {

                table[i][j] = 0;

                x = i;
                y = j;
                return;

            }

        }
    }
}

int tb_hash() {

    int h = table[0][0]*pow(9, 0) + table[0][1]*pow(9, 1) + table[0][3]*pow(9, 2) + table[1][0]*pow(9, 3) + table[1][1]*pow(9, 4) + table[1][2]*pow(9, 5) + table[2][0]*pow(9, 6) + table[2][1]*pow(9, 7) + table[2][2]*pow(9, 8);
    
    return h;

}

bool check_table() {

    int c = 1;

    if(table[2][2] != 0) {
        return false;
    }

    for(int i = 0; i < 2; i++)
        for(int j; j < 2; j++) {

            if(table[i][j] != c && (i != 2 && j != 2))
                return false;

        }

    return true;

}

void solve() {

    cout << x << ':' << y << endl;

    if(solved)
        return;

    combs.insert(tb_hash());

    if(check_table()){

        solved = true;
        for(int i = 0; i < moves_made; i++)
            cout << moves[i];

        return;

    }

    // up
    if(x + 1 < 3) {
        
        print_table();
        table[x][y] = table[x+1][y];

        x++;
        moves[moves_made] = 'u';
        moves_made++;

        table[x][y] = 0;

        if(combs.find(tb_hash()) == combs.end()) {
            //cout << "heyu";
            solve();
            cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@22\n";
        }

        table[x][y] = table[x-1][y];

        moves_made--;
        x--;

        table[x][y] = 0;
        print_table();
    }

    // down
    if(x - 1 > 0) {

        table[x][y] = table[x-1][y];

        x--;
        moves[moves_made] = 'd';
        moves_made++;

        table[x][y] = 0;

        if(combs.find(tb_hash()) == combs.end()) {

            //cout << "heyd";
            solve();
            cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@22\n";
        }

        table[x][y] = table[x+1][y];

        moves_made--;
        x++;

        table[x][y] = 0;
    }

    // right
    if(y + 1 < 3) {

        table[x][y] = table[x][y+1];

        y++;
        moves[moves_made] = 'r';
        moves_made++;

        table[x][y] = 0;

        if(combs.find(tb_hash()) == combs.end()) {

            //cout << "heyr";
            solve();
            cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@22\n";
        }

        table[x][y] = table[x][y-1];

        moves_made--;
        y--;

        table[x][y] = 0;
    }

    // left
    if(y - 1 > 0) {

        table[x][y] = table[x][y-1];

        y--;
        moves[moves_made] = 'l';
        moves_made++;

        table[x][y] = 0;

        if(combs.find(tb_hash()) == combs.end()) {

            //cout << "heyl";
            solve();
            cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@22\n";
        }

        table[x][y] = table[x][y+1];

        moves_made--;
        y++;

        table[x][y] = 0;
    }

    

}

int main(void) {

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {

        moves_made = 0;
        solved = false;

        combs.clear();

        read_table();

        solve();

        if(!solved)
            cout << "unsolvable\n";

        cout << '\n';
    }


}