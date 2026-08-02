class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& coins,int amount){
        if(amount==0) return 0;
        int ans = INT_MAX;
        if(dp[amount]!=-1){
            return dp[amount];
        }
        for(int coin:coins){
            if(amount>=coin){
                int res = solve(coins,amount-coin);
                if(res!=INT_MAX){
                    ans = min(ans,1+res);
                }
            }
        }
        dp[amount] = ans;
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.assign(amount+1,-1);
        int ans = solve(coins,amount);
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna