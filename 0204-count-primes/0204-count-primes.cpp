class Solution {
public:
    int countPrimes(int n) {
        if(n<=1) return 0;
        bool arr[n+1];
        memset(arr,true,sizeof(arr));
        arr[0]=arr[1]=false;
        int count = 0;
        for(int i=2;i<=sqrt(n);i++){
            if(arr[i]==true){
                for(int j=i*i;j<=n;j+=i){
                        arr[j]=false;
                }
            }
        }
        for(int i=2;i<n;i++){
            if(arr[i]==true) count++;
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna