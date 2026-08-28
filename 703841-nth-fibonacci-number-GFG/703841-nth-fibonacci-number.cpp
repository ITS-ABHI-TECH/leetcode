class Solution {
  public:
    int nthFibonacci(int n) {
        // code here
        if(n==1) return 1;
        if(n==0) return 0;
        return nthFibonacci(n-1)+nthFibonacci(n-2);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna