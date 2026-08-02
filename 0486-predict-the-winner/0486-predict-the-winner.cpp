class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>&nums,int left,int right){
        int n = nums.size();
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        if(left>right) return 0;
        if(left==right) return nums[right];
        int pickleft = nums[left] - solve(nums,left+1,right);
        int pickright = nums[right] - solve(nums,left,right-1);
        dp[left][right] =  max(pickleft,pickright);
        return dp[left][right];
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n,vector<int>(n,-1));
        return solve(nums,0,nums.size()-1)>=0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna