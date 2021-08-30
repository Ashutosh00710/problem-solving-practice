#include<bits/stdc++.h>

using namespace std;

vector<vector<bool>> subsetSum(int arr[], int n, int sum) {
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

  return dp;
}

int minDifference(int arr[], int n)  {
	int sum = accumulate(arr, arr + n, 0);
  vector<vector<bool>> dp = subsetSum(arr, n, sum);

  int num;
  for (int i = 0; i <= sum / 2; i++) {
      if (dp[n][i]) num = i;
  }

  return sum - (num << 1);
}

int main() {
    int arr[] = {31, 26, 33, 21, 40};
    cout << minDifference(arr, 5);
}