/*

A pair of numbers has a unique LCM but a single number can be the LCM of more than one possible
pairs. For example 12 is the LCM of (1, 12), (2, 12), (3,4) etc. For a given positive integer N, the
number of different integer pairs with LCM is equal to N can be called the LCM cardinality of that
number N. In this problem your job is to find out the LCM cardinality of a number.

Input:
The input file contains at most 101 lines of inputs. Each line contains an integer N (0 < N <= 2 ∗ 109).
Input is terminated by a line containing a single zero. This line should not be processed.

Output:
For each line of input except the last one produce one line of output. This line contains two integers
N and C. Here N is the input number and C is its cardinality. These two numbers are separated by a
single space.

Sample Input:
2
12
24
101101291
0

Sample Output:
2 2
12 8
24 11
101101291 

*/

#include <iostream>
#include <vector>

using namespace std; 

vector<int> divisors;

int gcd(int a, int b) {
    
    if(a == 0)
        return b;

    return gcd(b % a, a);    

}

int lcm(int a, int b) {

    return (a / gcd(a, b)) * b;

}

int main(void) {

    int n;
    while(cin >> n) {

        if(n == 0)
            return 0;

        divisors.clear();

        for(int i = 1; i*i <= n; i++) {

            if(n % i == 0) {
                divisors.push_back(i);

                int di = n / i;
                if(i != di)
                    divisors.push_back(di);

            }

        }

        int c = 0;
        for(size_t i = 0; i < divisors.size(); i++) {
            for(size_t j = i; j < divisors.size(); j++) {
            
                if(lcm(divisors[i], divisors[j]) == n)
                    c++;

            }
        }

        cout << n << ' ' << c << '\n';

    }

    return 0;
}