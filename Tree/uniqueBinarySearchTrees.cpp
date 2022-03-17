/*
    Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

    Example 1:
      Input: n = 3
      Output: 5
*/

int numTrees(int n) {
    int dp[n+1];

    for(int i = 0; i <= n; i++) {
        dp[i] = 1;
    }

    for(int i = 2; i <= n; i++) {
        int total = 0;
        for(int j = 1; j <= i; j++) {
            int left = j-1;
            int right = i - j;
            total += dp[left] * dp[right];
        }

        dp[i] = total;
    }

    return dp[n];
}

// Time Complexity = O(n^2)
