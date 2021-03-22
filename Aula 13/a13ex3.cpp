/*

Karel is a robot who lives in a rectangular coordinate system where each place is designated by a set of
integer coordinates (x and y). Your job is to design a program that will help Karel pick up a number
of beepers that are placed in her world. To do so you must direct Karel to the position where each
beeper is located. Your job is to write a computer program that finds the length of the shortest path
that will get Karel from her starting position, to each of the beepers, and return back again to the
starting position.
Karel can only move along the x and y axis, never diagonally. Moving from one position (i, j) to
an adjacent position (i, j + 1), (i, j − 1), (i − 1, j), or (i + 1, j) has a cost of one.
You can assume that Karel’s world is never larger than 20 × 20 squares and that there will never
be more than 10 beepers to pick up. Each coordinate will be given as a pair (x, y) where each value
will be in the range 1 through the size of that particular direction of the coordinate system.

Input:
First there will be a line containing the number of scenarios you are asked to help Karel in. For each
scenario there will first be a line containing the size of the world. This will be given as two integers
x-size and y-size). Next there will be one line containing two numbers giving the starting position of
Karel. On the next line there will be one number giving the number of beepers. For each beeper there
will be a line containing two numbers giving the coordinates of each beeper.

Output:
The output will be one line per scenario, giving the minimum distance that Karel has to move to get
from her starting position to each of the beepers and back again to the starting position.

Sample Input:
1
10 10
1 1
4
2 3
5 5
9 4
6 5

Sample Output:
The shortest path has length 24

*/

#include <iostream>

int dp[31];

int p[1000];
int w[1000];

int main(void) {

    // Recebe os casos de teste.
	int tests; 
    std::cin >> tests;

	for(int t = 0; t < tests; t++) {

        // Limpa a DP.
        for(int i = 0; i < 31; i++) dp[i] = 0;

        // Pega o número de itens.
        int n;
		std::cin >> n;

        // Recebe os itens.
        for(int i = 0; i < n; i++)
            std::cin >> p[i] >> w[i];

        // Faz a DP de peso para valor.
		for(int i = 0; i < n; i++) {
			for(int j = 30; j >= w[i]; j--) {
				if(dp[j] < dp[j - w[i]] + p[i])
					dp[j] = dp[j - w[i]] + p[i];
            }
		}

        // Recebe quantas pessoas tem no grupo.
        int g;
		std::cin >> g;

        // Recebe e soma os valores máximos que cada pessoa pode carregar.
        int r = 0;
		for(int i = 0; i < g; i++) {

            int mw;
			std::cin >> mw;

			r += dp[mw];

		}

        // Printa.
		std::cout << r << std::endl;

	}

    return 0;

}