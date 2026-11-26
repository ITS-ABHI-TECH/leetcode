import java.util.*;

class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {

        Stack<Integer> stack = new Stack<>();
        HashMap<Integer, Integer> map = new HashMap<>();

        // Find next greater elements in nums2
        for (int num : nums2) {

            while (!stack.isEmpty() && stack.peek() < num) {

                map.put(stack.pop(), num);
            }

            stack.push(num);
        }

        // Build answer for nums1
        int[] ans = new int[nums1.length];

        for (int i = 0; i < nums1.length; i++) {

            ans[i] = map.getOrDefault(nums1[i], -1);
        }

        return ans;
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna