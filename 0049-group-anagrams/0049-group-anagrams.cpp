class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        for(string word:strs ){
            string key ="";
            vector<int> freq(26,0);
            for(char c: word){
                freq[c-'a']++;
            }
            for(int x:freq){
                key+=to_string(x)+"#";
            }
            mp[key].push_back(word);
        }
        for(auto x : mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna