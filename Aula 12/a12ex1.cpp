// UVA 11450 Wedding Shopping

#include <iostream>

int n_tests, money, c_garm;

int price[21][21];
int dp[201][21];

# define INF 0x3f3f3f3f

int max(int a, int b) {

	if(a > b) return a;
	return b;

}

int solve(int cash, int garm) {

	if (cash < 0) return -INF;
	if (garm == c_garm) return (money - cash);
	if (dp[cash][garm] != -1) return dp[cash][garm];

	int r = -1;
	for (int i = 1; i <= price[garm][0]; i++) {

		r = max(r, solve(cash - price[garm][i], garm + 1));

	}

	dp[cash][garm] = r;

	return r;

}


int main(void) {

	std::cin >> n_tests;

	for(int t = 0; t < n_tests; t++) {

		for(int i = 0; i < 201; i++)
			for(int j = 0; j < 21; j++)
				dp[i][j] = -1;

		std::cin >> money >> c_garm;

		for(int i = 0; i < c_garm; i++) {

			std::cin >> price[i][0];
			for(int j = 1; j <= price[i][0]; j++) std::cin >> price[i][j];

		}

		int r = solve(money, 0);

		if (r < 0) {

			std::cout << "no solution" << std::endl;
			continue;

		}

		std::cout << r << std::endl;

	}

	return 0;
}
