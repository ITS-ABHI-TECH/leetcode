class Solution {
  public:
    vector<int> dp;
    int solve(int i){
        if(i<=1) return i;
        if(dp[i]!=-1) return dp[i];
        dp[i] = solve(i-1)+solve(i-2);
        return dp[i];
    }
    int nthFibonacci(int n) {
        // code here
        dp.assign(n+1,-1);
        solve(n);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna