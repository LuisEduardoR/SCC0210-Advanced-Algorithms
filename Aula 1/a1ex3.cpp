/*

You are given an array A of n positive integers Ai, 1 <= i <= n, 1 <= Ai <= 109. 
Find out how many different integers A contains. 
For example A = {1, 3, 2, 4, 1, 1, 3, 2} has 4 different integers in it (1, 2, 3 and 4).

Input:

The input consists of one line with integer n (1 <= n <= 105). 
Then the next line has n space separated positive integers A1, A2,..., An
(1 <= Ai <= 109).

Output:

Your program should print one integer: the number of different values in array A.

Sample Input:
10
12 15 6 9 4 15 9 12 9 4

Sample Output:
5

*/

#include <set>
#include <iostream>

int main(void) {

	int n;

	std::cin >> n;

	std::set<int> s;

	for(int i = 0; i < n; i++) {

		int t;
	
		std::cin >> t;

		s.insert(t);

	}

	std::cout << s.size() << '\n';

	return 0;
}
