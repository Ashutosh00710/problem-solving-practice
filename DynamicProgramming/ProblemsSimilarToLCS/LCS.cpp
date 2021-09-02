#include<iostream>

int** create_2D_array(size_t row, size_t col) {
  int **dp = new int *[row];
    for(int i = 0; i < row; i++)
      dp[i] = new int[col];

    return dp;
}

inline int max(int a, int b) {
    return a > b ? a : b;
}

int LCS(std::string str1, std::string str2, int m, int n) {
  if(m == 0 || n == 0) {
      return 0;
  }

  if(str1[m - 1] == str2[n - 1]) {
      return 1 + LCS(str1, str2, m - 1, n - 1);
  } else {
      return max(
        LCS(str1, str2, m - 1, n),
        LCS(str1, str2, m, n - 1)
      );
  }
}

int LCS(std::string str1, std::string str2, int m, int n, int **memo) {
  if(m == 0 || n == 0) {
      return memo[m][n] = 0;
  }

  if (memo[m][n] != -1) return memo[m][n];

  if(str1[m - 1] == str2[n - 1]) {
      return memo[m][n] = 1 + LCS(str1, str2, m - 1, n - 1);
  } else {
      return memo[m][n] = max(
        LCS(str1, str2, m - 1, n),
        LCS(str1, str2, m, n - 1)
      );
  }
}

int LCSBottomUp(std::string str1, std::string str2, size_t m, size_t n) {
    int **dp = create_2D_array(m + 1, n + 1);
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
          if(str1[i - 1] == str2[j - 1]) {
            dp[i][j] = 1 + dp[i - 1][j - 1];
          } else {
              dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
          }
        }
    }

    return dp[m][n];
}

int main() {
    std::string str1 = "abcdgh";
    std::string str2 = "abedfhr";
    int **memo = create_2D_array(str1.length() + 1, str2.length() + 1);
    for (int i = 0; i <= str1.length(); i++) {
        for (int j = 0; j <= str2.length(); j++) {
            memo[i][j] = -1;
        }
    }
    std::cout << LCS(str1, str2, str1.length(), str2.length()) << "\n";
    std::cout << LCS(str1, str2, str1.length(), str2.length(), memo) << "\n";
    std::cout << LCSBottomUp(str1, str2, str1.length(), str2.length()) << "\n";
}
