class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        
        int total = 0;
        for (int num : nums)
            total += num;
        
        int target = total - x;
        
        // We need to keep a subarray with sum = target
        if (target < 0)
            return -1;
        
        if (target == 0)
            return n;
        
        int left = 0;
        int sum = 0;
        int maxLen = -1;
        
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            
            while (sum > target && left <= right) {
                sum -= nums[left];
                left++;
            }
            
            if (sum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        
        return maxLen == -1 ? -1 : n - maxLen;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna