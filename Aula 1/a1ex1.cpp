// https://codeforces.com/contest/130/problem/H 

#include <stack>
#include <cstdio>

int main(void) {

	char c[128];
	std::stack<char> s;

	scanf(" %s", c);

	int i = 0;
	while((c[i] == '(' || c[i] == ')') && i < 128) {

		if(c[i] == '(')
			s.push('(');
		else if (c[i] == ')' && s.size() > 0)
			s.pop();
		else if (c[i] == ')' && s.size() == 0)
		{
			printf("NO\n");
			return 0;
		}
		

		i++;

	}

	if(s.size() != 0)
		printf("NO\n");
	else
		printf("YES\n");

	return 0;
}
