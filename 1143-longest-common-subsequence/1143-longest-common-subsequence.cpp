class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int j,string &text1,string &text2){
        if(i>=text1.size()||j>=text2.size()) return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(text1[i]==text2[j]){
            return dp[i][j]=1+solve(i+1,j+1,text1,text2);
        }
        return dp[i][j] = max(solve(i+1,j,text1,text2),solve(i,j+1,text1,text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.assign(text1.size(),vector<int>(text2.size(),-1));
        return solve(0,0,text1,text2);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna