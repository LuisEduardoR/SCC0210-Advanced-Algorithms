/*

John has n tasks to do. Unfortunately, the tasks are not independent and the execution of one task is
only possible if other tasks have already been executed.

Input:
The input will consist of several instances of the problem. Each instance begins with a line containing
two integers, 1 <= n <= 100 and m. n is the number of tasks (numbered from 1 to n) and m is the
number of direct precedence relations between tasks. After this, there will be m lines with two integers
i and j, representing the fact that task i must be executed before task j.
An instance with n = m = 0 will finish the input.

Output:
For each instance, print a line with n integers representing the tasks in a possible order of execution.

Sample Input:
5 4
1 2
2 3
1 3
1 5
0 0

Sample Output:
1 4 2 5 3

*/

# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>

using namespace std;

int n, m;

vector<int> graph[101];
vector<int> task_list;

int vis[101];
int deg_in[101];
int deg_out[101];

bool cmp(int a, int b) {

    return deg_out[a] < deg_out[b];

}

void bfs(int s) {

    queue<int> q;

    vis[s] = -1;

    q.push(s);
    task_list.push_back(s);

    while(!q.empty()) {

        int u = q.front();
        q.pop();

        for(size_t i = 0; i < graph[u].size(); i++) {

            int v = graph[u][i];

            if(vis[v] != -1) {
            
                vis[v]++;

                if( vis[v] >= deg_in[v]) {

                    vis[v] = -1;

                    q.push(v);
                    task_list.push_back(v);

                }
            }
        }
    }
}

int main(void) {

    while(true) {

        cin >> n >> m;

        if(n == 0 && m == 0) return 0;

        // Reset variables.
        for(int i = 1; i <= n; i++) {
            vis[i] = 0;
            deg_in[i] = 0;
            graph[i].clear();
        }
        task_list.clear();

        // Reads input.
        for(int i = 1; i <= m; i++) {

            int u, v;
            cin >> u >> v;

            graph[u].push_back(v);
            deg_out[u]++;
            deg_in[v]++;

        }

        // Orders input, cuz run.codes...
        for(int i = 1; i <= n; i++)
            sort(graph[i].begin(), graph[i].end(), cmp);

        // Do all tasks.
        for(int i = n; i > 0; i--) {

            if(vis[i] == 0) {

                for(int j = n; j > 0; j--) {
                    
                    if(vis[j] >= deg_in[j] && vis[j] != -1) {
                        bfs(j);
                        break;
                    }
                }

            }
        }

        // Print results.
        for(size_t i = 0; i < task_list.size(); i++) {

            if(i == 0) cout << task_list[i];
            else cout << ' ' << task_list[i];

        }

        cout << endl;
    }
}