class Solution {
  public:
    int peakElement(vector<int> &nums) {
        // code here
        int left = 0;
        int right = nums.size()-1;
        while(left<right){
            int mid = left+(right-left)/2;
            if(nums[mid]>nums[mid+1]){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna