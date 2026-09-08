class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0) return true;
        int n1 = flowerbed.size();
        for(int i=0;i<n1;i++){
            if(flowerbed[i]==0 && (i==0 || flowerbed[i-1]==0) &&  (i==n1-1 ||flowerbed[i+1]==0)){
                flowerbed[i]=1;
                n--;
                if(n==0) {
                    return true;
                }
            }
        }
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna