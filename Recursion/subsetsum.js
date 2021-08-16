function subsetSum(array, sum) {
  const dp = Array(array.length + 1)
    .fill(null)
    .map(() => Array(sum + 1).fill(null));
  for (let i = 0; i <= array.length; i++) {
    for (let j = 0; j <= sum; j++) {
      if (i == 0) dp[0][j] = false;
      if (j == 0) dp[i][0] = true;
    }
  }

  for (let i = 1; i <= array.length; i++) {
    for (let j = 1; j <= sum; j++) {
      if (array[i - 1] <= j) {
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - array[i - 1]];
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  return dp[array.length][sum];
}

class Solution {
  constructor() {
    this.subsetSum = this.subsetSum.bind(this);
    this.isSubsetSum = this.isSubsetSum.bind(this);
  }

  isSubsetSum(set, n, sum) {
    if (sum == 0) return true;
    if (n == 0) return false;

    if (set[n - 1] > sum) return this.isSubsetSum(set, n - 1, sum);

    return (
      this.isSubsetSum(set, n - 1, sum) ||
      this.isSubsetSum(set, n - 1, sum - set[n - 1])
    );
  }

  subsetSum(array, sum) {
    const dp = Array(array.length + 1)
      .fill(null)
      .map(() => Array(sum + 1).fill(null));
    for (let i = 0; i <= array.length; i++) {
      for (let j = 0; j <= sum; j++) {
        if (i == 0) dp[0][j] = false;
        if (j == 0) dp[i][0] = true;
      }
    }

    for (let i = 1; i <= array.length; i++) {
      for (let j = 1; j <= sum; j++) {
        if (array[i - 1] <= j) {
          // either you can take the element or you can not take the element
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - array[i - 1]];
        } else {
          // don't do anything and copy the value from the previous row
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[array.length][sum];
  }

  equalPartition(array) {
    const sum = array.reduce((_, __) => _ + __);
    if (sum & 1) return false;
    // recursion
    // return this.isSubsetSum(array, array.length, sum / 2);
    // dp
    return this.subsetSum(array, sum / 2);
  }
}

console.log(new Solution().equalPartition([1, 5, 5, 11]));

// console.log(subsetSum([1, 2, 3, 5, 4], 8));
