#include<bits/stdc++.h>

using namespace std;

int countSubsets(vector<int>& nums, int sum) {
  size_t n = nums.size();
  vector<vector<int>> dp(n + 1, vector<int>(sum + 1));

  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= sum; j++) {
      if(i == 0) dp[i][j] = 0;
      if(j == 0) dp[i][j] = 1;
    }
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= sum; j++) {
      if(nums[i - 1] <= j) {
          dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
      } else {
          dp[i][j] = dp[i - 1][j];
      }
    }
  }

  return dp[n][sum];
}

int numberOfSubsets(vector<int>& nums, int target) {
  int sum = accumulate(nums.begin(), nums.end(), 0);
  int requiredSubsetSum = (sum + target)/2;
  return countSubsets(nums, requiredSubsetSum);
}
