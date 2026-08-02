class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>&piles,int left,int right){
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        if(left>right) return 0;
        if(left==right) return piles[right];
        int pickleft = piles[left] - solve(piles,left+1,right);
        int pickright = piles[right] - solve(piles,left,right-1);
        dp[left][right] =  max(pickleft,pickright);
        return dp[left][right];
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n,vector<int>(n,-1));
        return solve(piles,0,piles.size()-1)>=0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna