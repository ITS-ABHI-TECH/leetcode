class Solution {

    public int findTargetSumWays(int[] nums, int target) {

        int sum = 0;

        for (int num : nums) {
            sum += num;
        }

        // Target cannot exceed total sum
        if (Math.abs(target) > sum) {
            return 0;
        }

        // Subset target must be an integer
        if ((sum + target) % 2 != 0) {
            return 0;
        }

        int subsetTarget = (sum + target) / 2;

        int[] dp = new int[subsetTarget + 1];

        dp[0] = 1;

        for (int num : nums) {

            for (int j = subsetTarget; j >= num; j--) {

                dp[j] += dp[j - num];
            }
        }

        return dp[subsetTarget];
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna