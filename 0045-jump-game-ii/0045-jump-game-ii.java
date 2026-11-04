class Solution {
    public int jump(int[] nums) {
        int farthest = 0;
        int jump =0;
        int currentend = 0;
        for(int i=0;i<nums.length-1;i++){
            farthest = Math.max(farthest,i+nums[i]);
            if(i==currentend){
                jump++;
                currentend = farthest;
            }
        }
        return jump;
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna