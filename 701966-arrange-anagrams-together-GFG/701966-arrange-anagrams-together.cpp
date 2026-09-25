class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
       vector<vector<string>> ans;
       unordered_map<string,vector<string>> mp;
       for(string word : arr){
           vector<int> freq(26,0);
           for(char c:word ){
               freq[c-'a']++;
           }
           string key = "";
           for(int x:freq){
               key+=to_string(x)+"#";
           }
           mp[key].push_back(word);
       }
       for(auto x:mp){
           ans.push_back(x.second);
       }
       return ans;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna