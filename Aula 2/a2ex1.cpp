// https://codeforces.com/contest/920/problem/C

#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(void) {

	int n;
	scanf(" %d", &n);

	vector<int> vet(n + 1);
	vet[0] = 0;
	for(int i = 1; i <= n;i++)
		scanf(" %d", &(vet[i]));

	char* swap = (char*)malloc(n * sizeof(char));
	scanf(" %s", swap);

	for(int i = 1; i <= n; i++) {

		if(vet[i] != i) {

			int t = vet[i];
			int dif = 0;
			while(i + dif != t) {

				if(swap[i + dif - 1] == '1') {
					vet[i + dif] = vet[i + dif + 1];
					vet[i + dif + 1] = t;
					dif++;

				} else {
				
					free(swap);
					printf("NO\n");
					return 0;

				}

			}

		}


	}

	free(swap);
	printf("YES\n");

	return 0;

}
