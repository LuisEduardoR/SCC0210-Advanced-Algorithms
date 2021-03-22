/*

A ring is composed of n (even number) circles as shown in diagram. Put natural numbers {1, 2, … , n} 
into each circle separately, and the sum of numbers in two adjacent circles should be a prime. 
Note: the number of first circle should always be 1. 

Input :
n (0 < n <= 16) 

Output :
The output format is shown as sample below. Each row represents a series of circle numbers in 
the ring beginning from 1 clockwisely and anticlockwisely. The order of numbers must satisfy 
the above requirements. 
You are asked to write a program that completes above process. 

Sample Input: 
6 
8 

Sample Output: 
Case 1: 
1 4 3 2 5 6 
1 6 5 2 3 4 
<empty line> 
Case 2: 
1 2 3 8 5 6 7 4 
1 2 5 8 3 4 7 6 
1 4 7 6 5 8 3 2 
1 6 7 4 3 8 5 2 
<empty line> 

*/

#include <vector>
#include <cstdio>

using namespace std;

vector<int> g_vet;
vector<vector<int>> solutions;

int n;

bool isPrime(int p) {

    if(p == 2)
        return true;

    if(p <= 2 || p % 2 == 0)
        return false;

    for(int i = 3; i*i <= p; i+=2) {
        
        if(p % i == 0)
            return false;

    }

    return true;

}

void solve() {

    printf("%d << \n", (int)g_vet.size());

    if(g_vet.size() == n) { // Found a solution.

        if(n == 1)
            return;

        if(isPrime(i + g_vet[0])) {

            vector<int> new_solution;
            for(size_t j = 0; j < g_vet.size(); j++)
                new_solution.push_back(g_vet[j]);

            solutions.push_back(new_solution);

        }

    } else if(g_vet.size() == 0) { // Start.

            g_vet.push_back(1);
            solve();
            g_vet.pop_back();
            

    } else {

        for(int i = 2; i <= n; i++) {

            if(isPrime(g_vet[g_vet.size() - 1] + i)){

                for(size_t j = 0; j < g_vet.size(); j++) {

                    if(g_vet[j] == i)
                        return;

                }
                g_vet.push_back(i);

            } else {
                return;
            }

            solve();
            g_vet.pop_back();

        }
    }
}

int main(void) {  

    int caseNum = 1;

    while(scanf(" %d", &n)) {

        printf("Case %d:\n", caseNum);
        caseNum++;

        solve();

        for(size_t i = 0; i < solutions.size(); i++) {

            for(size_t j = 0; j < solutions[i].size(); j++) {

                printf("%d ", solutions[i][j]);

            }
            putchar('\n');

        }

        
        for(size_t i = 0; i < solutions.size(); i++) {

            printf("%d ", solutions[i][0]);
            for(size_t j = solutions[i].size() - 1; j >= 1; j--) {

                printf("%d ", solutions[i][j]);

            }
            putchar('\n');

        }
    }
}