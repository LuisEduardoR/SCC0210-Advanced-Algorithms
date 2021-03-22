/*

A friend of you is doing research on the Traveling Knight Problem (TKP) where you are to find the
shortest closed tour of knight moves that visits each square of a given set of n squares on a chessboard
exactly once. He thinks that the most difficult part of the problem is determining the smallest number
of knight moves between two given squares and that, once you have accomplished this, finding the tour
would be easy.
Of course you know that it is vice versa. So you offer him to write a program that solves the
”difficult” part.
Your job is to write a program that takes two squares a and b as input and then determines the
number of knight moves on a shortest route from a to b.

Input:
The input file will contain one or more test cases. Each test case consists of one line containing two
squares separated by one space. A square is a string consisting of a letter (a..h) representing the column
and a digit (1..8) representing the row on the chessboard.

Output:
For each test case, print one line saying ‘To get from xx to yy takes n knight moves.’.

Sample Input:
e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6

Sample Output:
To get from e2 to e4 takes 2 knight moves.
To get from a1 to b2 takes 4 knight moves.
To get from b2 to c3 takes 2 knight moves.
To get from a1 to h8 takes 6 knight moves.
To get from a1 to h7 takes 5 knight moves.
To get from h8 to a1 takes 6 knight moves.
To get from b1 to c3 takes 1 knight moves.
To get from f6 to f6 takes 0 knight moves.

*/

# include <iostream>
# include <queue>
# include <utility>

using namespace std;

pair<int,int> start, fim;
int vis[8][8];

void bfs() {

    queue<pair<int,int>> q;
    q.push(start);
    vis[start.first][start.second] = 0;    

    while(!q.empty()) {

        pair<int,int> u = q.front();
        q.pop();

        int prev_vis = vis[u.first][u.second];

        if(u.first + 2 < 8) {
            
            if(u.second + 1 < 8) {

                if(vis[u.first+2][u.second+1] == -1) {
                    vis[u.first+2][u.second+1] = prev_vis + 1;
                    q.push(make_pair(u.first+2,u.second+1));
                }

            }

            if(u.second - 1 >= 0) {
                
                if(vis[u.first+2][u.second-1] == -1) {
                    vis[u.first+2][u.second-1] = prev_vis + 1;
                    q.push(make_pair(u.first+2,u.second-1));
                }

            }

        }

        if(u.first - 2 >= 0) {
                
            if(u.second + 1 < 8) {

                if(vis[u.first-2][u.second+1] == -1) {
                    vis[u.first-2][u.second+1] = prev_vis + 1;
                    q.push(make_pair(u.first-2,u.second+1));
                }

            }

            if(u.second - 1 >= 0) {
                
                if(vis[u.first-2][u.second-1] == -1) {
                    vis[u.first-2][u.second-1] = prev_vis + 1;
                    q.push(make_pair(u.first-2,u.second-1));
                }

            }

        }

        if(u.second + 2 < 8) {
            
            if(u.first + 1 < 8) {

                if(vis[u.first+1][u.second+2] == -1) {
                    vis[u.first+1][u.second+2] = prev_vis + 1;
                    q.push(make_pair(u.first+1,u.second+2));
                }

            }

            if(u.first - 1 >= 0) {
                
                if(vis[u.first-1][u.second+2] == -1) {
                    vis[u.first-1][u.second+2] = prev_vis + 1;
                    q.push(make_pair(u.first-1,u.second+2));
                }

            }

        }

        if(u.second - 2 >= 0) {
                
            if(u.first + 1 < 8) {

                if(vis[u.first+1][u.second-2] == -1) {
                    vis[u.first+1][u.second-2] = prev_vis + 1;
                    q.push(make_pair(u.first+1,u.second-2));
                }

            }

            if(u.first - 1 >= 0) {
                
                if(vis[u.first-1][u.second-2] == -1) {
                    vis[u.first-1][u.second-2] = prev_vis + 1;
                    q.push(make_pair(u.first-1,u.second-2));
                }

            }

        }
    }
}

int main(void) {

    char ori[3], des[3];

    while(cin >> ori) {

        cin >> des;

        start.first = ori[0] - 'a';
        start.second = ori[1] - '1';

        fim.first = des[0] - 'a';
        fim.second = des[1] - '1';

        for(int i = 0 ; i < 8; i++)
            for(int j = 0; j < 8; j++)
                vis[i][j] = -1;

        bfs();

        cout << "To get from " << ori << " to " << des << " takes " << vis[fim.first][fim.second] << " knight moves." << endl;

    }
}