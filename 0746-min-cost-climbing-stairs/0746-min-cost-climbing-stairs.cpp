class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& cost,int i){
        int n = cost.size();
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i]; 
        }
        dp[i] = cost[i]+min(solve(cost,i+1),solve(cost,i+2));
        return dp[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        dp.assign(cost.size(),-1);
        return min(solve(cost,0),solve(cost,1));
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna