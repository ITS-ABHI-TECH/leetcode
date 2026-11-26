import java.util.*;

class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {

        int[] dist = new int[n];

        Arrays.fill(dist, Integer.MAX_VALUE);

        dist[src] = 0;

        // At most k stops means at most k+1 edges
        for (int i = 0; i <= k; i++) {

            int[] temp = dist.clone();

            for (int[] flight : flights) {

                int u = flight[0];
                int v = flight[1];
                int price = flight[2];

                if (dist[u] != Integer.MAX_VALUE) {

                    temp[v] = Math.min(
                        temp[v],
                        dist[u] + price
                    );
                }
            }

            dist = temp;
        }

        return dist[dst] == Integer.MAX_VALUE ? -1 : dist[dst];
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna