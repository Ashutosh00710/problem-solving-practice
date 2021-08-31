#include<bits/stdc++.h>

using namespace std;

class Solution
{
  public:
  //Function to find the maximum number of cuts.
  int maximizeTheCuts(int n, int x, int y, int z) {
    int wt[3] = {x, y, z};
    int dp[3 + 1][n + 1];
    for (int i = 0; i <= 3; i++) {
      for (int j = 0; j <= n; j++) {
        if (i == 0) dp[i][j] = INT_MIN;
        if (j == 0) dp[i][j] = 0;
      }
    }

    for (int i = 1; i <= 3; i++) {
      for (int j = 1; j <= n; j++) {
        if(wt[i - 1] <= j) {
          dp[i][j] = max(
            1 + dp[i][j - wt[i - 1]],
            dp[i - 1][j]
          );
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    return dp[3][n] < 0 ? 0 : dp[3][n];
  }
};
