import java.util.*;

class Solution {

    public List<String> findAllConcatenatedWordsInADict(String[] words) {

        Set<String> set = new HashSet<>(Arrays.asList(words));

        List<String> ans = new ArrayList<>();

        for (String word : words) {

            if (word.length() == 0) continue;

            set.remove(word);

            int n = word.length();

            boolean[] dp = new boolean[n + 1];

            dp[0] = true;

            for (int i = 1; i <= n; i++) {

                for (int j = 0; j < i; j++) {

                    if (dp[j] && set.contains(word.substring(j, i))) {

                        dp[i] = true;
                        break;
                    }
                }
            }

            if (dp[n]) {
                ans.add(word);
            }

            set.add(word);
        }

        return ans;
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna