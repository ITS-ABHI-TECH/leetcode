class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void find(int i,vector<int> &nums){
        if(i>=nums.size()){
            ans.push_back(temp);
            return;
        }
        //not take /exclude
        find(i+1,nums);
        //take /include
        temp.push_back(nums[i]);
        find(i+1,nums);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        find(0,nums);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna