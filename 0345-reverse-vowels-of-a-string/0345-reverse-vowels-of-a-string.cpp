class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
            int i =0;
            int j=n-1;
            while(i<j){
                // if((s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'|| s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U') && (s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'|| s[j]=='A'||s[j]=='E'||s[j]=='I'||s[j]=='O'||s[j]=='U')){
                //     int temp = s[i];
                //     s[i] = s[j];
                //     s[j] = temp;
                // }
                if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u'&& s[i]!='A'&&s[i]!='E'&&s[i]!='I'&&s[i]!='O'&&s[i]!='U'){
                    i++;
                }
                else if(s[j]!='a'&&s[j]!='e'&&s[j]!='i'&&s[j]!='o'&&s[j]!='u'&& s[j]!='A'&&s[j]!='E'&&s[j]!='I'&&s[j]!='O'&&s[j]!='U'){
                    j--;
                }else{
                    int temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                    i++;
                    j--;
                }
            }
        return s;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna