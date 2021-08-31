package Java;

public class CoinChange {
  private static int minCoins(int[] coins, int amount) {
    int dp[][] = new int[coins.length + 1][amount + 1];
    // Initialization of Matrix
    for (int i = 0; i <= coins.length; i++) {
      for (int j = 0; j <= amount; j++) {
        // Initialization of 1st row and 1st column
        if (i == 0)
          dp[i][j] = Integer.MAX_VALUE - 1;
        if (j == 0)
          dp[i][j] = 0;

        // Initialization of 2nd row
        if (i == 1 && j > 0) {
          if (j % coins[0] != 0) {
            dp[i][j] = Integer.MAX_VALUE - 1;
          } else {
            dp[i][j] = j / coins[0];
          }
        }
      }
    }
    dp[0][0] = Integer.MAX_VALUE - 1;
    // Iteration
    for (int i = 2; i <= coins.length; i++) {
      for (int j = 1; j <= amount; j++) {
        if (coins[i - 1] <= j) {
          dp[i][j] = Math.min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    if (dp[coins.length][amount] == Integer.MAX_VALUE - 1)
      return -1;
    else
      return dp[coins.length][amount];
  }

  public static void main(String[] args) {
    int coins[] = { 1, 2, 5 };
    int amount = 11;
    System.out.println(minCoins(coins, amount));
  }
}
