class Solution {

    int count = 0;

    public int countRangeSum(int[] nums, int lower, int upper) {

        int n = nums.length;

        long[] prefix = new long[n + 1];

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        mergeSort(prefix, 0, n, lower, upper);

        return count;
    }

    void mergeSort(long[] arr, int left, int right,
                   int lower, int upper) {

        if (left >= right) return;

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, lower, upper);
        mergeSort(arr, mid + 1, right, lower, upper);

        int j = mid + 1;
        int k = mid + 1;

        for (int i = left; i <= mid; i++) {

            while (j <= right && arr[j] - arr[i] < lower) {
                j++;
            }

            while (k <= right && arr[k] - arr[i] <= upper) {
                k++;
            }

            count += k - j;
        }

        merge(arr, left, mid, right);
    }

    void merge(long[] arr, int left, int mid, int right) {

        long[] temp = new long[right - left + 1];

        int i = left;
        int j = mid + 1;
        int k = 0;

        while (i <= mid && j <= right) {

            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        while (j <= right) {
            temp[k++] = arr[j++];
        }

        for (int x = 0; x < temp.length; x++) {
            arr[left + x] = temp[x];
        }
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna