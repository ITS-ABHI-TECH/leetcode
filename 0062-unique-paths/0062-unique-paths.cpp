class Solution {
public:
    int m,n;
    vector<vector<int>> dp;
    int solve(int i,int j){
        if(i==m-1&&j==n-1){
            return 1;
        }
        if(i>=m || j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        dp[i][j] = solve(i+1,j)+solve(i,j+1);
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        this->m = m;
        this->n = n;
        dp.assign(m,vector<int>(n,-1));
        return solve(0,0);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna