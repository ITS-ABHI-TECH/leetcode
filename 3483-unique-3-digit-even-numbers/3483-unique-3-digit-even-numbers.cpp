class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {0};

        for (int d : digits)
            freq[d]++;

        int ans = 0;

        for (int a = 1; a <= 9; a++) {       // hundreds
            if (freq[a] == 0) continue;
            freq[a]--;

            for (int b = 0; b <= 9; b++) {   // tens
                if (freq[b] == 0) continue;
                freq[b]--;

                for (int c = 0; c <= 8; c += 2) { // ones: even
                    if (freq[c] > 0)
                        ans++;
                }

                freq[b]++;
            }

            freq[a]++;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna