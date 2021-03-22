/*
Frosh commencing their studies at Waterloo have diverse
interests, as evidenced by
their desire to take various combinations of courses
from among those available.
University administrators
are uncomfortable with this
situation, and therefore wish
to offer a conformity prize
to frosh who choose the
most popular combination of
courses. How many frosh
will win the prize?

Input:
The input consists of several test cases followed by a line containing ‘0’. Each test case begins with
an integer 1 ≤ n ≤ 10000, the number of frosh. For each frosh, a line follows containing the course
numbers of five distinct courses selected by the frosh. Each course number is an integer between 100
and 499.
The popularity of a combination is the number of frosh selecting exactly the same combination
of courses. A combination of courses is considered most popular if no other combination has higher
popularity.

Output:
For each line of input, you should output a single line giving the total number of students taking some
combination of courses that is most popular.

Sample Input:
3
100 101 102 103 488
100 200 300 101 102
103 102 101 488 100
3
200 202 204 206 208
123 234 345 456 321
100 200 300 400 444
0

Sample Output:
2
3

*/

#include <set>
#include <map>
#include <utility>
#include <cstdio>

using namespace std;

long long int lld_pow(int n, int p) {

	long long int r = 1;
	for(int i = 0; i < p; i++)
		r *= n;

	return r;

}

long long int hash_set(set<int> *s) {

	long long int r = 0;

	int i = 0;
	for(auto it = (*s).begin(); it != (*s).end(); it++) {

		r += (long long int)(*it) * lld_pow(1000, i);
		i++;

	}
	return r;

}

int main(void) {

	int t = -1;
	while(t != 0) {

		scanf(" %d", &t);
		if(t == 0)
			break;
		
		map<long long int, int> frosh;
		for(int i = 0; i < t; i++){
			
			set<int> ts;
			for(int i = 0; i < 5; i++) {

				int crs;
				scanf(" %d", &crs);
				ts.insert(crs);
				
			}

			long long int hash = hash_set(&ts);
			auto it = frosh.find(hash);	
			if(it != frosh.end())
				(*it).second++;
			else
				frosh.insert(make_pair(hash, 1));		

		}

		int max_freq = 0;
		for(auto it = frosh.begin(); it != frosh.end(); it++) {
			if((*it).second > max_freq)
				max_freq = (*it).second;
		}

		int appearences = 0;
		for(auto it = frosh.begin(); it != frosh.end(); it++) {

			if((*it).second == max_freq)
				appearences += (*it).second;
		}

		printf("%d\n", appearences);
	}

	return 0;
}
