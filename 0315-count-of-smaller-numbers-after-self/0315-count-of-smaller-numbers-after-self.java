class Solution {

    public List<Integer> countSmaller(int[] nums) {
        int n = nums.length;

        int[] count = new int[n];
        int[] indices = new int[n];

        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        mergeSort(nums, indices, count, 0, n - 1);

        List<Integer> ans = new ArrayList<>();

        for (int x : count) {
            ans.add(x);
        }

        return ans;
    }

    void mergeSort(int[] nums, int[] indices, int[] count,
                   int left, int right) {

        if (left >= right) return;

        int mid = left + (right - left) / 2;

        mergeSort(nums, indices, count, left, mid);
        mergeSort(nums, indices, count, mid + 1, right);

        merge(nums, indices, count, left, mid, right);
    }

    void merge(int[] nums, int[] indices, int[] count,
               int left, int mid, int right) {

        int[] temp = new int[right - left + 1];

        int i = left;
        int j = mid + 1;
        int k = 0;

        int smaller = 0;

        while (i <= mid && j <= right) {

            if (nums[indices[j]] < nums[indices[i]]) {

                temp[k++] = indices[j++];
                smaller++;

            } else {

                count[indices[i]] += smaller;
                temp[k++] = indices[i++];
            }
        }

        while (i <= mid) {
            count[indices[i]] += smaller;
            temp[k++] = indices[i++];
        }

        while (j <= right) {
            temp[k++] = indices[j++];
        }

        for (int x = 0; x < temp.length; x++) {
            indices[left + x] = temp[x];
        }
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna