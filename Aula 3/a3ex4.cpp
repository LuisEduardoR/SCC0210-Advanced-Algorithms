/*

Given a specified total t and a list of n integers, find all distinct sums using numbers from the list that
add up to t. For example, if t = 4, n = 6, and the list is [4, 3, 2, 2, 1, 1], then there are four different
sums that equal 4: 4, 3+1, 2+2, and 2+1+1. (A number can be used within a sum as many times as it
appears in the list, and a single number counts as a sum.) Your job is to solve this problem in general.

Input:
The input file will contain one or more test cases, one per line. Each test case contains t, the total,
followed by n, the number of integers in the list, followed by n integers x1, . . . , xn. If n = 0 it signals
the end of the input; otherwise, t will be a positive integer less than 1000, n will be an integer between 1
and 12 (inclusive), and x1, . . . , xn will be positive integers less than 100. All numbers will be separated
by exactly one space. The numbers in each list appear in nonincreasing order, and there may be
repetitions.

Output:
For each test case, first output a line containing ‘Sums of ’, the total, and a colon. Then output each
sum, one per line; if there are no sums, output the line ‘NONE’. The numbers within each sum must
appear in nonincreasing order. A number may be repeated in the sum as many times as it was repeated
in the original list. The sums themselves must be sorted in decreasing order based on the numbers
appearing in the sum. In other words, the sums must be sorted by their first number; sums with the
same first number must be sorted by their second number; sums with the same first two numbers must
be sorted by their third number; and so on. Within each test case, all sums must be distinct; the same
sum cannot appear twice.

Sample Input:
4 6 4 3 2 2 1 1
5 3 2 1 1
400 12 50 50 50 50 50 50 25 25 25 25 25 25
0 0

Sample Output:
Sums of 4:
4
3+1
2+2
2+1+1
Sums of 5:
NONE
Sums of 400:
50+50+50+50+50+50+25+25+25+25
50+50+50+50+50+25+25+25+25+25+25

*/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int t, n;
multiset<int, greater<int>> ordered;
vector<int> list;
vector<bool> picked;
int total;
int sums;

set<vector<int>, greater<vector<int>>> solutions;

void solve(int c) {

    if((unsigned)c == list.size() || total == t) {

        if(total == t) {

            sums++;

            vector<int> n_sol;
            for(unsigned i = 0; i < list.size(); i++) {

                if(picked[i])
                    n_sol.push_back(list[i]);

            }

            solutions.insert(n_sol);

        }

        return;

    }

    //pick
    picked[c] = true;
    total += list[c];
    solve(c + 1);
    picked[c] = false;
    total -= list[c];

    //don't pick
    solve(c + 1);

}

int main(void) {

    n = 42;
    while(n != 0){
        
        ordered.clear();
        list.clear();

        cin >> t >> n;
        for(int i = 0; i < n; i++) {

            int t;
            cin >> t;
            ordered.insert(t);

        }

        if(n == 0)
            break;

        for(auto it = ordered.begin(); it != ordered.end(); it++)
            list.push_back(*it);

        solutions.clear();

        picked.resize(n);
        for(int i = 0; i < n; i++) {
            picked[i] = false;
        }

        total = 0;
        sums = 0;

        cout << "Sums of " << t << ":\n";
        solve(0);

        for(auto it = solutions.begin(); it != solutions.end(); it++) {
            for(unsigned i = 0; i < (*it).size(); i++) {
                if(i != 0)
                    cout << "+";
                cout << (*it)[i];
            }
            cout << "\n";
        }

        if(sums == 0)
            cout << "NONE\n";

    }
    


    return 0;

}