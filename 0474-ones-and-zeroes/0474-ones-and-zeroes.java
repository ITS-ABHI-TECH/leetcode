class Solution {

    public int findMaxForm(String[] strs, int m, int n) {

        int[][] dp = new int[m + 1][n + 1];

        for (String s : strs) {

            int zeros = 0;
            int ones = 0;

            // Count zeros and ones
            for (char ch : s.toCharArray()) {

                if (ch == '0') {
                    zeros++;
                } else {
                    ones++;
                }
            }

            // 0/1 Knapsack: iterate backwards
            for (int i = m; i >= zeros; i--) {

                for (int j = n; j >= ones; j--) {

                    dp[i][j] = Math.max(
                        dp[i][j],
                        1 + dp[i - zeros][j - ones]
                    );
                }
            }
        }

        return dp[m][n];
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna