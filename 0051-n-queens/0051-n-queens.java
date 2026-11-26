import java.util.*;

class Solution {

    List<List<String>> result = new ArrayList<>();

    boolean[] cols;
    boolean[] diagonal1;
    boolean[] diagonal2;

    public List<List<String>> solveNQueens(int n) {

        cols = new boolean[n];

        diagonal1 = new boolean[2 * n];
        diagonal2 = new boolean[2 * n];

        char[][] board = new char[n][n];

        for (int i = 0; i < n; i++) {
            Arrays.fill(board[i], '.');
        }

        solve(0, n, board);

        return result;
    }

    void solve(int row, int n, char[][] board) {

        // All queens placed successfully
        if (row == n) {

            List<String> temp = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                temp.add(new String(board[i]));
            }

            result.add(temp);
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
            board[row][col] = 'Q';

            cols[col] = true;
            diagonal1[d1] = true;
            diagonal2[d2] = true;

            // Move to next row
            solve(row + 1, n, board);

            // Backtracking
            board[row][col] = '.';

            cols[col] = false;
            diagonal1[d1] = false;
            diagonal2[d2] = false;
        }
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna