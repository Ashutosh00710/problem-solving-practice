#include<bits/stdc++.h>

using namespace std;

// Recursive Approach
int knapsackRecursive(int wt[], int val[], int W, int n) {
  if(n == 0 || W == 0) {
      return 0;
  }

  if(wt[n - 1] <= W) {
      return max(
        val[n - 1] + knapsackRecursive(wt, val, W - wt[n - 1], n),
        knapsackRecursive(wt, val, W, n - 1)
      );
  } else if(wt[n-1] > W) {
      return knapsackRecursive(wt, val, W, n - 1);
  }
}

// Memoization
// Top Down Approach
int knapsackMemoized(int wt[], int val[], int W, int n,  vector<vector<int>>& memo) {
  if(n == 0 || W == 0) {
      return memo[n][W] = 0;
  }

  if (memo[n][W] != -1) return memo[n][W];

  if(wt[n - 1] <= W) {
      return memo[n][W] = max(
        val[n - 1] + knapsackMemoized(wt, val, W - wt[n - 1], n, memo),
        knapsackMemoized(wt, val, W, n - 1, memo)
      );
  } else if(wt[n-1] > W) {
      return memo[n][W] = knapsackMemoized(wt, val, W, n - 1, memo);
  }
}

// Bottom Up Approach
// Convert: 1. Base Case -> Initialization of DP matrix
//          2. Recursion -> Iteration

int knapsackIterative(int wt[], int val[], int W, int n,  vector<vector<int>>& dp) {
  // Base case conversion
  /*
    if(n == 0 || W == 0) {
      return 0;
    }
  */

  for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= W; j++) {
          if (i == 0 || j == 0) dp[i][j] = 0;
      }
  }

  /*
    Convert recursion
    if(wt[n - 1] <= W) {
      return max(
        val[n - 1] + knapsackRecursive(wt, val, W - wt[n - 1], n),
        knapsackRecursive(wt, val, W, n - 1)
      );
    } else if(wt[n-1] > W) {
        return knapsackRecursive(wt, val, W, n - 1);
    }
  */

  for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= W; j++) {
          if(wt[i - 1] <= j) {
              dp[i][j] = max(
                val[i - 1] + dp[i][j - wt[i - 1]],
                dp[i - 1][j]
              );
          } else {
              dp[i][j] = dp[i - 1][j];
          }
      }
  }

  return dp[n][W];
}

int main() {
    int val[] = { 1, 4, 5, 7 };
    int wt[] = { 1, 3, 4, 5 };
    int W = 8;
    int n = sizeof(val) / sizeof(val[0]);
    vector<vector<int>> memo(n + 1, vector<int>(W + 1, -1));
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    cout << knapsackRecursive(wt, val, W, n) << "\n";  // Output: 11
    cout << knapsackMemoized(wt, val, W, n, memo) << "\n"; // Output: 11
    cout << knapsackIterative(wt, val, W, n, dp) << "\n"; // Output: 11
    return 0;
}
