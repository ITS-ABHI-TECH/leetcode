class Solution {
public:
    unordered_map<int,int> mp;
    vector<int> ans;
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        mp[root->val]++;
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        int maxfreq = 0;
        for(auto it:mp){
            maxfreq = max(maxfreq,it.second);
        }
        for(auto it:mp){
            if(it.second == maxfreq) ans.push_back(it.first);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna