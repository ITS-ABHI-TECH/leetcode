class Solution {
public:
    int m,n;
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& grid,int i,int j){
        if(i==m-1&&j==n-1) return grid[i][j];
        if(i>=m||j>=n) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int best = min(solve(grid,i+1,j),solve(grid,i,j+1));
        if(best==INT_MAX) return INT_MAX;
        dp[i][j] = grid[i][j]+best;
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        dp.assign(m,vector<int>(n,-1));
        return solve(grid,0,0);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna