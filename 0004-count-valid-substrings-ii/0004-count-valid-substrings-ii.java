class Solution {
    public long countValidSubstrings(String s) {
        long ans =0;
        int lastA = -1;
        int startAB = -1;
        int badStart = -1;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='a'){
                lastA = i;
            }else if(s.charAt(i)=='b'){
                if(lastA != -1){
                    startAB = lastA;
                }
            }else if(s.charAt(i)=='c'){
                if(startAB !=-1){
                    badStart = Math.max(badStart,startAB);
                }
            }
            ans +=(i-badStart);
        }
        return ans;
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna