class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1000000007;

        long long dp = 0;
        long long last[26] = {};

        for (char c : s) {
            int x = c - 'a';

            long long newdp = (2 * dp + 1 - last[x] + MOD) % MOD;

            last[x] = (dp + 1) % MOD;

            dp = newdp;
        }

        return dp;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna