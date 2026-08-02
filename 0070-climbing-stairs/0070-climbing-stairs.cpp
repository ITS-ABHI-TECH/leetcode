class Solution {
public:
    vector<int> dp;
    int solve(int n,int i){
        if(i==n){
            return 1;
        }
        if(i>n) return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
        dp[i] = solve(n,i+1)+solve(n,i+2);
        return dp[i];
    }
    int climbStairs(int n) {
        dp.assign(n,-1);
        return solve(n,0);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna