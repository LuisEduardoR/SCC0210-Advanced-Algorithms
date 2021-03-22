// Hacker Rank The Coin Change Problem

# include <iostream>

int dp[10001][101];

void solve( int n, int m, int *coins) { 
  
    for (int i = 1; i <= n; i++) { 
        for (int j = 0; j < m; j++) {
             
            // Pega.
            int pg = 0;
            if(i - coins[j] >= 0) pg = dp[i - coins[j]][j]; 
  
            // Não pega.
            int npg = 0;
            if(j > 0) npg = dp[i][j - 1]; 
  
            // Calcula soluções.
            dp[i][j] = pg + npg;

        } 
    }
}

int main(void) { 
    
    int n, m;
    int coins[101];

    // Recebe os valores.
    std::cin >> n >> m;
    for(int i  = 0; i < m; i++)
        std::cin >> coins[i];

    // Inicializa a DP.
    for (int i = 0; i < m; i++) dp[0][i] = 1;

    // Pega a solução.
    solve(n, m, coins);

    // Printa.
    std::cout << dp[n][m - 1] << std::endl; 

    return 0; 
}
