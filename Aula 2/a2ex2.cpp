// UVA 11995 I Can Guess the Data Structure!

# include <stack>
# include <queue>
# include <cstdio>

using namespace std;

int main (void) {

	int n;
	while(scanf(" %d", &n) != EOF) {

		bool is_s = true;
		bool is_q = true;
		bool is_pq = true;

		stack<int> s;
		queue<int> q;
		priority_queue<int, vector<int>, less<int>> pq;

		for(int i = 0; i < n; i++) {

			int c;
			scanf(" %d", &c);
			if(c == 1) {

				int t;
				scanf(" %d", &t);

				s.push(t);
				q.push(t);
				pq.push(t);

			} else {

				int t;
				scanf(" %d", &t);
				
				if(s.empty() || q.empty() || pq.empty()) {

					is_s = false;
					is_q = false;
					is_pq = false;
					continue;

				}

				int c_s = s.top();
					s.pop();

				int c_q = q.front();
				q.pop();

				int c_pq = pq.top();
				pq.pop();

				if(t != c_s)
					is_s = false;

				if(t != c_q)
					is_q = false;

				if(t != c_pq)
					is_pq = false;

			}
		}

		int candidates = 0;

		if(is_s)
			candidates++;
		if(is_q)
			candidates++;
		if(is_pq)
			candidates++;

		if(candidates == 0)
			printf("impossible\n");
		else if(candidates == 1) {
			if(is_s)
				printf("stack\n");
			else if (is_q)
				printf("queue\n");
			else
				printf("priority queue\n");
		} else
			printf("not sure\n");

	}

	return 0;

}
