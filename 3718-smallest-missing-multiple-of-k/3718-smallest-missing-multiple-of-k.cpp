class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        uint64_t x[2] = {0, 0};
        for (auto& c : nums)
            if (!(c % k)) {
                int i = c / k - 1;
                x[i >> 6] |= 1ULL << (i & 63);
            }

        int z = x[0] == -1ULL;
        return (z * 64 + bit_width(++x[z] & -x[z])) * k;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna