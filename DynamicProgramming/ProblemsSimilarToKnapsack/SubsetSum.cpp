#include<bits/stdc++.h>

using namespace std;

bool subsetSum(int arr[], int n, int sum) {
  if (n == 0 && sum != 0) return false;

  if (n == 0 && sum == 0) return true;

  if (sum == 0) return true;

  if (arr[n - 1] <= sum) {
    return (
      subsetSum(arr, n - 1, sum - arr[n - 1]) || subsetSum(arr, n - 1, sum)
    );
  } else {
    return subsetSum(arr, n - 1, sum);
  }
}

bool subsetSumMemoizer(int arr[], int n, int sum, vector<vector<bool>> memo) {
  if (n == 0 && sum != 0) return (memo[n][sum] = false);

  if (n == 0 && sum == 0) return (memo[n][sum] = true);

  if (sum == 0) return (memo[n][sum] = true);

  if (memo[n][sum]) return memo[n][sum];

  if (arr[n - 1] <= sum) {
    return (memo[n][sum] =
      subsetSumMemoizer(arr, n - 1, sum - arr[n - 1], memo) ||
      subsetSumMemoizer(arr, n - 1, sum, memo));
  } else {
    return (memo[n][sum] = subsetSumMemoizer(arr, n - 1, sum, memo));
  }
}

bool subsetSumIterative(int arr[], int n, int sum) {
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
    // initialize dp
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= sum; j++) {
        if (i == 0) {
          dp[i][j] = false;
        }
        if (j == 0) {
          dp[i][j] = true;
        }
      }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sum; j++) {
      if (arr[i - 1] <= j) {
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  return dp[n][sum];
}
