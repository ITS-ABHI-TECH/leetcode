class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int max = 0;
        vector<bool> ans(candies.size(),true);
        for(int i=0;i<n;i++){
            if((candies[i])>max) max = candies[i];
        }
        for(int i=0;i<n;i++){
            if(candies[i]+extraCandies<max){
                ans[i] = false;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna