class Solution {

    int count = 0;

    boolean[] cols;
    boolean[] diagonal1;
    boolean[] diagonal2;

    public int totalNQueens(int n) {

        cols = new boolean[n];
        diagonal1 = new boolean[2 * n];
        diagonal2 = new boolean[2 * n];

        solve(0, n);

        return count;
    }

    void solve(int row, int n) {

        // All queens successfully placed
        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; col++) {

            int d1 = row - col + n;
            int d2 = row + col;

            // Check whether position is safe
            if (cols[col] || diagonal1[d1] || diagonal2[d2]) {
                continue;
            }

            // Place queen
            cols[col] = true;
            diagonal1[d1] = true;
            diagonal2[d2] = true;

            // Move to next row
            solve(row + 1, n);

            // Backtracking
            cols[col] = false;
            diagonal1[d1] = false;
            diagonal2[d2] = false;
        }
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna