class Solution {
public:
    vector<int> dp;
    int solve(int i){
        if(i==1 || i==0) return i;
        if(dp[i]!=-1){
            return dp[i];
        }
        dp[i] = solve(i-1)+solve(i-2);
        return dp[i];
    }
    int fib(int n) {
        dp.assign(n+1,-1);
        return solve(n);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna