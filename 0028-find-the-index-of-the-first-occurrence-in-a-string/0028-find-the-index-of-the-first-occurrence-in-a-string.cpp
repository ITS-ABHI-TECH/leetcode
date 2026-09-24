class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        vector<int> lps(m,0);
        for(int i=1,len=0;i<m;){
            if(needle[i]==needle[len]){
                lps[i]=++len;
                i++;
            }else if(len>0){
                len = lps[len-1];
            }else{
                lps[i]=0;
                i++;
            }
        }
        int i=0,j=0;
        while(i<n){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            if(j==m){
                return i-j;
            }
            else if(i<n && haystack[i]!=needle[j]){
                if(j>0) j = lps[j-1];
                else{
                    i++;
                }
            }

        }
        return -1;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna