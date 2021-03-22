/*

In this problem we will be considering a game played with four wheels. Digits ranging from 0 to 9
are printed consecutively (clockwise) on the periphery of each wheel. The topmost digits of the wheels
form a four-digit integer. For example, in the following figure the wheels form the integer 8056. Each
wheel has two buttons associated with it. Pressing the button marked with a left arrow rotates the
wheel one digit in the clockwise direction and pressing the one marked with the right arrow rotates it
by one digit in the opposite direction.
The game starts with an initial configuration of the wheels. Say, in the initial configuration the
topmost digits form the integer S1S2S3S4. You will be given some (say, n) forbidden configurations
Fi1 Fi2 Fi3 Fi4
(1 ≤ i ≤ n) and a target configuration T1T2T3T4. Your job will be to write a program that
can calculate the minimum number of button presses required to transform the initial configuration to
the target configuration by never passing through a forbidden one.

Input:
The first line of the input contains an integer N giving the number of test cases to follow.
The first line of each test case contains the initial configuration of the wheels specified by 4 digits.
Two consecutive digits are separated by a space. The next line contains the target configuration. The
third line contains an integer n giving the number of forbidden configurations. Each of the following n
lines contains a forbidden configuration. There is a blank line between two consecutive input sets.

Output:
For each test case in the input print a line containing the minimum number of button presses required.
If the target configuration is not reachable then print ‘-1’.

Sample Input:
2
8 0 5 6
6 5 0 8
5
8 0 5 7
8 0 4 7
5 5 0 8
7 5 0 8
6 4 0 8
0 0 0 0
5 3 1 7
8
0 0 0 1
0 0 0 9
0 0 1 0
0 0 9 0
0 1 0 0
0 9 0 0
1 0 0 0
9 0 0 0

Sample Output:
14
-1

*/

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <string>

using namespace std;

int start, target;

set<int> forbs;

vector<int> vet[10000];

int to_number(int* arr) {

    return (arr[0] * 1000) + (arr[1] * 100) + (arr[2] * 10) + arr[3];

}

bool is_forbs(int v) {

    if(forbs.find(v) != forbs.end())
        return true;

    return false;

}

void build_graph() {

    int v;
    string buf;

    for(int i = 0; i < 10000; i++) {
        
        //x--- +
        buf = to_string(i);
        buf[0]++;
        if(buf[0] == ':') buf[0] = '0';
        v = stoi(buf);
        if(!is_forbs(v))
            vet[i].push_back(v);

        //x--- -
        buf = to_string(i);
        buf[0]--;
        if(buf[0] == '/') buf[0] = '9';
        v = stoi(buf);
        if(!is_forbs(v))
            vet[i].push_back(v);

        //-x-- +
        buf = to_string(i);
        buf[1]++;
        if(buf[1] == ':') buf[1] = '0';
        v = stoi(buf);
        if(!is_forbs(v))
            vet[i].push_back(v);

        //-x-- -
        buf = to_string(i);
        buf[1]--;
        if(buf[1] == '/') buf[1] = '9';
        v = stoi(buf);
        if(!is_forbs(v))
            vet[i].push_back(v);

        //--x- +
        buf = to_string(i);
        buf[2]++;
        if(buf[2] == ':') buf[2] = '0';
        v = stoi(buf);
        if(!is_forbs(v))
            vet[i].push_back(v);

        //--x- -
        buf = to_string(i);
        buf[2]--;
        if(buf[2] == '/') buf[2] = '9';
        v = stoi(buf);
        if(!is_forbs(v))
            vet[i].push_back(v);

        //---x +
        buf = to_string(i);
        buf[3]++;
        if(buf[3] == ':') buf[3] = '0';
        v = stoi(buf);
        if(!is_forbs(v))
            vet[i].push_back(v);

        //---x -
        buf = to_string(i);
        buf[3]--;
        if(buf[3] == '/') buf[3] = '9';
        v = stoi(buf);
        if(!is_forbs(v))
            vet[i].push_back(v);

    }


}

int bfs() {

    int vis[10000];
    for(int i = 0; i < 10000; i++) {
        vis[i] = -1;
    }

    queue<int> q;
    q.push(start);

    vis[start] = 0;

    int u, v;
    while(!q.empty()){
        
        u = q.front();
        q.pop();

        for(size_t i = 0; i < vet[u].size(); i++) {

            v = vet[u][i];
                if(vis[v] == -1) {
                vis[v] = vis[u] + 1;

                q.push(v);
            }
        }        
    }
    

    return vis[target];

}

int main(void) {

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {

        int temp[4];
        cin >> temp[0] >> temp[1] >> temp[2] >> temp[3];
        start = to_number(temp);

        cin >> temp[0] >> temp[1] >> temp[2] >> temp[3];
        target = to_number(temp);

        int f;
        cin >> f;
        for(int j = 0; j < f; j++) {

            cin >> temp[0] >> temp[1] >> temp[2] >> temp[3];
            int fbr = to_number(temp);

            forbs.insert(fbr);

        }

        for(int k = 0; k < 10000; k++)
            vet[k].clear();

        build_graph();

        cout << bfs() << endl;

    }



}