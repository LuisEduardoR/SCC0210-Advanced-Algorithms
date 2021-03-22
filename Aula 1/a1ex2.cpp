// UVA 540 Team Queue

#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <cstdio>

using namespace std;

int main(void) {

	int scenerio = 1;

	int t = -1;
	while (t != 0) {

		scanf(" %d", &t);
		if(t == 0)
			break;

		map<int,int> members;

		for(int i = 0; i < t; i++) {

			int s = 0;
			scanf(" %d", &s);

			for(int j = 0; j < s; j++) {

				int m;
				scanf(" %d", &m);
				members.insert(make_pair(m,i));

			}
		}

		printf("Scenario #%d\n", scenerio);
		scenerio++;

		vector<queue<int>> teams(t);
		queue<int> q;

		char cmd[32] = "HELLOWORLD\0";
		while(cmd[0] != 'S') {

			scanf(" %s", cmd);
			if(cmd[0] == 'E') {

				int s;
				scanf(" %d", &s);

				auto tm = members.find(s);
				if(tm != members.end()){

					if(teams[(*tm).second].empty())
						q.push((*tm).second);
				
					teams[(*tm).second].push(s);
				}

				

			} else if(cmd[0] == 'D') {				
	
				int s = q.front();

				int m = teams[s].front();
				teams[s].pop();

				if(teams[s].empty())
					q.pop();

				printf("%d\n", m);

			}

		}

		printf("\n");

	}

}
