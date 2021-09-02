#include<iostream>

int** create_2D_array(size_t row, size_t col) {
  int **dp = new int *[row];
    for(int i = 0; i < row; i++)
      dp[i] = new int[col];

    return dp;
}

int find_max(int **dp, size_t m, size_t n) {
    int max = -1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if(dp[i][j] > max) {
                max = dp[i][j];
            }
        }
    }
    return max;
}

int LCSubstring(std::string str1, std::string str2, size_t m, size_t n) {
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
                dp[i][j] = 0;
            }
        }
    }

    return find_max(dp, m, n);
}

int main() {
    std::string str1 = "abcdgh";
    std::string str2 = "abedfhr";
    std::cout << LCSubstring(str1, str2, str1.length(), str2.length()) << "\n";
}
