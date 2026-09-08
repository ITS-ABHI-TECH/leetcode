// class Solution {
//   public:
//     vector<vector<int>> targetSumComb(vector<int> &arr, int target) {
//         // code here
        
//     }
// };
class Solution {
public:
    void backtrack(vector<int> & candidates,int target,vector<vector<int>>& res,vector<int>& comb,int start){
        if(target == 0){
            res.push_back(comb);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if(candidates[i]>target) continue; //pruning
            comb.push_back(candidates[i]);
            backtrack(candidates,target-candidates[i],res,comb,i);
            comb.pop_back();//backtrack

        }
    }
    vector<vector<int>> targetSumComb(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        backtrack(candidates,target,res,comb,0);
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna