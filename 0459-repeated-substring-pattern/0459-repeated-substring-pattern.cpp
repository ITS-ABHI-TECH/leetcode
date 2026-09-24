class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n =s.size();
        vector<int> lps(n,0);

        for(int i=1,len=0;i<n;){
            if(s[i]==s[len]){
                lps[i] = ++len;
                i++;
            }
            else if(len>0){
                len = lps[len-1];
            }else{
                lps[i++] =0;
            }
        }
        int patternLen = n-lps[n-1];
        return lps[n-1]>0 && n%patternLen == 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna