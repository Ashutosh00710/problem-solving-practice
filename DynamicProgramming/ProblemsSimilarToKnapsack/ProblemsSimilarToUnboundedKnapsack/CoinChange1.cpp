#include<bits/stdc++.h>

using namespace std;

// Coin Change (GFG) and Coin Change 2 (LeetCode)
// https://practice.geeksforgeeks.org/problems/coin-change2448/1#
int coin_change(int coins[], int n, int target) {
    int dp[n + 1][target + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            if (i == 0) dp[i][j] = 0;
            if (j == 0) dp[i][j] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
          if(coins[i - 1] <= j) {
              dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
          } else {
              dp[i][j] = dp[i - 1][j];
          }
        }
    }

    return dp[n][target];
}

// Number of Coin (GFG) and Coin Change (LeetCode)
// https://practice.geeksforgeeks.org/problems/number-of-coins1824/1
int coin_change2(int coins[], int n, int amount) {
    int dp[n + 1][amount + 1];
    // Initialization of Matrix
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= amount; j++) {
        // Initialization of 1st row and 1st column
        if (i == 0)
          dp[i][j] = INT_MAX - 1;
        if (j == 0)
          dp[i][j] = 0;

        // Initialization of 2nd row
        if (i == 1 && j > 0) {
          if (j % coins[0] != 0) {
            dp[i][j] = INT_MAX - 1;
          } else {
            dp[i][j] = j / coins[0];
          }
        }
      }
    }
    dp[0][0] = INT_MAX - 1;
    // Iteration
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j <= amount; j++) {
        if (coins[i - 1] <= j) {
          dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    if (dp[n][amount] == INT_MAX - 1)
      return -1;
    else
      return dp[n][amount];
}
