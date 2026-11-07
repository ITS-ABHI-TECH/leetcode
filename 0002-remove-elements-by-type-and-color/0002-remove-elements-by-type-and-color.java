class Solution {
    public boolean canRemoveAll(int[] types, int[] colors, int[] groupSize) {
        int n = types.length;
        int[] stType = new int[n];
        int[] stColor = new int[n];
        int[] stCount = new int[n];
        int top = -1;
        for(int i=0;i<n;i++){
            int type = types[i];
            int color = colors[i];
            if(top!=-1 && stType[top]==type&&stColor[top]==color){
                stCount[top]++;
            }else{
                top++;
                stType[top]=type;
                stColor[top]=color;
                stCount[top]=1;
            }
            if(stCount[top]==groupSize[type]){
                top--;
            }
        }
        return top == -1;
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna