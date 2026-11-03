class Solution {
    int firstelement(int[] nums,int target){
        int left = 0 ,right = nums.length - 1,ans =-1;
        while(left<=right){
            int mid = left +(right-left)/2;
            if(nums[mid]==target){
                ans =  mid;
                right = mid - 1;
            }else if(target>nums[mid]){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return ans;
    }
    int secondelement(int[] nums,int target){
        int left = 0 ,right = nums.length - 1,ans =-1;
        while(left<=right){
            int mid = left +(right-left)/2;
            if(nums[mid]==target){
                ans = mid;
                left = mid +1;
            }else if(target>nums[mid]){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return ans;
    }
    public int[] searchRange(int[] nums, int target) {
         int first = firstelement(nums,target);
        if(first==-1) return new int[]{-1,-1};
         int second = secondelement(nums,target);
        return new int[]{first,second};
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna