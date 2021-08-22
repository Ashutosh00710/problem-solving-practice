#include<bits/stdc++.h>

using namespace std;

// Recursive Approach
int knapsackRecursive(int wt[], int val[], int W, int n) {
  if(n == 0 || W == 0) {
      return 0;
  }

  if(wt[n - 1] <= W) {
      return max(
        val[n - 1] + knapsackRecursive(wt, val, W - wt[n - 1], n - 1),
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
        val[n - 1] + knapsackMemoized(wt, val, W - wt[n - 1], n - 1, memo),
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
        val[n - 1] + knapsackRecursive(wt, val, W - wt[n - 1], n - 1),
        knapsackRecursive(wt, val, W, n - 1)
      );
    } else if(wt[n-1] > W) {
        return knapsackRecursive(wt, val, W, n - 1);
    }
  */

  for (int array = 1; array <= n; array++) {
      for (int weight = 1; weight <= W; weight++) {
          if(wt[array - 1] <= weight) {
              dp[array][weight] = max(
                val[array - 1] + dp[array - 1][weight - wt[array - 1]],
                dp[array - 1][weight]
              );
          } else {
              dp[array][weight] = dp[array - 1][weight];
          }
      }
  }

  return dp[n][W];
}

int main() {
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    vector<vector<int>> memo(n + 1, vector<int>(W + 1, -1));
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    cout << knapsackRecursive(wt, val, W, n) << "\n";  // Output: 220
    cout << knapsackMemoized(wt, val, W, n, memo) << "\n"; // Output: 220
    cout << knapsackIterative(wt, val, W, n, dp) << "\n"; // Output: 220
    return 0;
}
