import java.util.*;

class Solution {

    public boolean makesquare(int[] matchsticks) {

        int sum = 0;

        for (int num : matchsticks) {
            sum += num;
        }

        if (sum % 4 != 0) {
            return false;
        }

        int target = sum / 4;

        Arrays.sort(matchsticks);

        int n = matchsticks.length;

        // Largest matchstick first
        for (int i = 0; i < n / 2; i++) {
            int temp = matchsticks[i];
            matchsticks[i] = matchsticks[n - 1 - i];
            matchsticks[n - 1 - i] = temp;
        }

        if (matchsticks[0] > target) {
            return false;
        }

        int[] sides = new int[4];

        return backtrack(matchsticks, sides, 0, target);
    }

    boolean backtrack(
        int[] matchsticks,
        int[] sides,
        int index,
        int target
    ) {

        // All matchsticks placed
        if (index == matchsticks.length) {
            return true;
        }

        int current = matchsticks[index];

        for (int i = 0; i < 4; i++) {

            // Don't exceed target
            if (sides[i] + current > target) {
                continue;
            }

            // Skip equivalent sides
            if (i > 0 && sides[i] == sides[i - 1]) {
                continue;
            }

            // Choose
            sides[i] += current;

            if (backtrack(
                matchsticks, sides, index + 1, target
            )) {
                return true;
            }

            // Backtrack
            sides[i] -= current;

            // If an empty side fails, other empty sides
            // will produce an equivalent result.
            if (sides[i] == 0) {
                return false;
            }
        }

        return false;
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna