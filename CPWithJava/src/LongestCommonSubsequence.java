package CPWithJava.src;

public class LongestCommonSubsequence {
    private static int LCS(
        StringBuffer str1, StringBuffer str2, int m, int n
    ) {
        if (m == 0 || n == 0) {
            return 0;
        }

        if (str1.charAt(m - 1) == str2.charAt(n - 1)) {
            return 1 + LCS(str1, str2, m - 1, n - 1);
        } else {
            return Math.max(
                LCS(str1, str2, m - 1, n),
                LCS(str1, str2, m, n - 1)
            );
        }
    }

    private static int LCSMemo(
        StringBuffer str1, StringBuffer str2, int m, int n, int memo[][]
    ) {
        if (m == 0 || n == 0) {
            return memo[m][n] = 0;
        }

        if (memo[m][n] != -1)
            return memo[m][n];

        if (str1.charAt(m - 1) == str2.charAt(n - 1)) {
            return memo[m][n] = 1 + LCSMemo(str1, str2, m - 1, n - 1, memo);
        } else {
            return memo[m][n] = Math.max(
                LCSMemo(str1, str2, m - 1, n, memo),
                LCSMemo(str1, str2, m, n - 1, memo)
            );
        }
    }

    private static int LCSBottomUp(
        StringBuffer str1, StringBuffer str2, int m, int n
    ) {
        int dp[][] = new int[m + 1][n + 1];
        for (int i = 0; i <= str1.length(); i++) {
            for (int j = 0; j <= str2.length(); j++) {
                if (i == 0)
                    dp[i][j] = 0;
                if (j == 0)
                    dp[i][j] = 0;
            }
        }

        for (int i = 1; i <= str1.length(); i++) {
            for (int j = 1; j <= str2.length(); j++) {
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[m][n];
    }


    public static void main(String[] args) throws Exception {
        StringBuffer str1 = new StringBuffer("abcdgh");
        StringBuffer str2 = new StringBuffer("abedfhr");
        int memo[][] = new int[str1.length() + 1][str2.length() + 1];
        for (int i = 0; i <= str1.length(); i++) {
            for (int j = 0; j <= str2.length(); j++) {
                memo[i][j] = -1;
            }
        }
        System.out.println(LCS(
                str1,
                str2,
                str1.length(),
                str2.length()
            )
        );
        System.out.println(LCSMemo(
                str1,
                str2,
                str1.length(),
                str2.length(),
                memo
            )
        );
        System.out.println(LCSBottomUp(
                str1,
                str2,
                str1.length(),
                str2.length()
            )
        );
    }
}
