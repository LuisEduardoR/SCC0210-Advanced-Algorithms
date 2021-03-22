// UVA 1203 Argus

#include <set>
#include <utility>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int gcd(int a, int b) {

	if(b == 0)
		return a;

	return gcd(b, a%b);

}

int main (void){

	set<pair<int, int>> s;
	vector<int> v;	

	char* buffer = (char*)malloc(1024 * sizeof(char));
	while(true) {

		scanf(" %[^\n]", buffer);
		
		if(strcmp(buffer, "#\0") == 0) {
			break;
		}
		
		int id, t;
		sscanf(buffer, "Register %d %d", &id, &t);

		s.insert(make_pair(id, t));

		v.push_back(t);

	}
	
	free(buffer);

	int g;

	if(v.size() == 0)
		return 0;
	else if(v.size() == 1)
		g = v[0];
	else {

		g = gcd(v[0], v[1]);
		for(size_t i = 2; i < v.size(); i++)
			g = gcd(g, v[i]);
	}

	int t;
	scanf(" %d", &t);

	int cur = 0;
	int time = g;
	while(cur < t) {

		for(auto it = s.begin(); it != s.end(); it++) {

			if(cur >= t)
				break;	

			if((*it).second != 0) {

				if(time % (*it).second == 0) {
					printf("%d\n",(*it).first);
					cur++;
				}

			} else {
				printf("%d\n",(*it).first);
				cur++;
			}

		}

		time+=g;

	}

}
