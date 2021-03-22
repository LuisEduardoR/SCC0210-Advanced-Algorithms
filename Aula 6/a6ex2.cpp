/*

The factorial function, n! is defined thus for n a non-negative integer:
0! = 1
n! = n * (n − 1)! (n > 0)
We say that a divides b if there exists an integer k such that
k * a = b

Input:
The input to your program consists of several lines, each containing two non-negative integers, n and
m, both less than 2^31.

Output:
For each input line, output a line stating whether or not m divides n!, in the format shown below.
Sample Input
6 9
6 27
20 10000
20 100000
1000 1009
Sample Output
9 divides 6!
27 does not divide 6!
10000 divides 20!
100000 does not divide 20!
1009 does not divide 1000!

*/

#include <iostream>
#include <cstring>
#include <utility>
#include <map>

using namespace std;

int main(void) {
    
    int n, m;
    while(cin >> n >> m) {
        
        if(m <= n) {
             cout << m << " divides " << n << "!\n";
             continue;
        }

        map<int, int> factors;

        // Get the factors of m.
        int a = m;
        int d = 2;
        while(a > 1) {

            while(a % d == 0) {
                
                auto it = factors.find(d);

                if(it == factors.end())
                    factors.insert(make_pair(d, 1));
                else
                    (*it).second++;              

                a /= d;

            }

            d++;
        }

        bool divisible = true;
        for(auto it = factors.begin(); it != factors.end(); it++) {

            int p = (*it).first;
            int freq = (*it).second;

            if(n / p < freq) {
                divisible = false;
            }

        }

        if(divisible) {
            cout << m << " divides " << n << "!\n";
        } else {
            cout << m << " does not divide " << n << "!\n";
        }

    } 
}