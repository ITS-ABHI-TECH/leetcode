import java.util.*;

class Solution {

    public int[][] outerTrees(int[][] trees) {

        Arrays.sort(trees, (a, b) -> {
            if (a[0] != b[0]) {
                return Integer.compare(a[0], b[0]);
            }

            return Integer.compare(a[1], b[1]);
        });

        List<int[]> lower = new ArrayList<>();

        // Build lower hull
        for (int[] p : trees) {

            while (lower.size() >= 2 &&
                   cross(
                       lower.get(lower.size() - 2),
                       lower.get(lower.size() - 1),
                       p
                   ) < 0) {

                lower.remove(lower.size() - 1);
            }

            lower.add(p);
        }

        List<int[]> upper = new ArrayList<>();

        // Build upper hull
        for (int i = trees.length - 1; i >= 0; i--) {

            int[] p = trees[i];

            while (upper.size() >= 2 &&
                   cross(
                       upper.get(upper.size() - 2),
                       upper.get(upper.size() - 1),
                       p
                   ) < 0) {

                upper.remove(upper.size() - 1);
            }

            upper.add(p);
        }

        // Combine both hulls and remove duplicates
        Map<Long, int[]> result = new LinkedHashMap<>();

        for (int[] p : lower) {
            long key = ((long) p[0] << 32) | (p[1] & 0xffffffffL);
            result.put(key, p);
        }

        for (int[] p : upper) {
            long key = ((long) p[0] << 32) | (p[1] & 0xffffffffL);
            result.put(key, p);
        }

        return result.values().toArray(new int[0][]);
    }

    private long cross(int[] a, int[] b, int[] c) {

        return (long) (b[0] - a[0]) * (c[1] - a[1])
             - (long) (b[1] - a[1]) * (c[0] - a[0]);
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna