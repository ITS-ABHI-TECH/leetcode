class Solution {
public:
    int solve(vector<int>&nums,int left,int right){
        // if(left>right) return 0;
        if(left==right) return nums[right];
        int pickleft = nums[left] - solve(nums,left+1,right);
        int pickright = nums[right] - solve(nums,left,right-1);
        return max(pickleft,pickright);
    }
    bool predictTheWinner(vector<int>& nums) {
        return solve(nums,0,nums.size()-1)>=0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna