class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pfreq(26,0);
        vector<int> wfreq(26,0);
        vector<int> ans;
        int left = 0;
        if(p.size()>s.size()) return {};
        for(int i=0;i<p.size();i++){
            pfreq[p[i]-'a']++;
            wfreq[s[i]-'a']++;
        }
        if(wfreq == pfreq)
            ans.push_back(0);
        for(int i=p.size();i<s.size();i++){
            wfreq[s[i] - 'a']++;
            if(i-left+1 > p.size()){
                wfreq[s[left]-'a']--;
                left++;
            }
            if(wfreq==pfreq){
                ans.push_back(left);
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna