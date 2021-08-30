#include<bits/stdc++.h>

using namespace std;

int countSubsets(int arr[], int n, int sum) {
  if (n == 0 && sum != 0) return 0;

  if (n == 0 && sum == 0) return 1;

  if (sum == 0) return 1;

  if (arr[n - 1] <= sum) {
    return (
      countSubsets(arr, n - 1, sum - arr[n - 1]) + countSubsets(arr, n - 1, sum)
    );
  } else {
    return countSubsets(arr, n - 1, sum);
  }
}

int countSubsetsMemoized(int arr[], int n, int sum, vector<vector<int>> memo) {
  if (n == 0 && sum != 0) return memo[n][sum] = 0;

  if (n == 0 && sum == 0) return memo[n][sum] = 1;

  if (sum == 0) return memo[n][sum] = 1;

  if (memo[n][sum]) return memo[n][sum];

  if (arr[n - 1] <= sum) {
    return memo[n][sum] = (
      countSubsets(arr, n - 1, sum - arr[n - 1]) + countSubsets(arr, n - 1, sum)
    );
  } else {
    return memo[n][sum] = countSubsets(arr, n - 1, sum);
  }
}

int countSubsetsMemoized(int arr[], int n, int sum, vector<vector<int>> dp) {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= sum; j++) {
      if (i == 0) {
        dp[i][j] = 0;
      }
      if (j == 0) {
        dp[i][j] = 1;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sum; j++) {
      if (arr[i - 1] <= j) {
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  return dp[n][sum];
}
