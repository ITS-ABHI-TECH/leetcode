class Solution {
  public:
    vector<int> ans;

    void DFS(vector<vector<int>> &graph, int start, vector<bool> &visited) {
        visited[start] = true;
        ans.push_back(start);

        // traverse
        for (int i = 0; i < graph[start].size(); i++) {
            if (visited[graph[start][i]] == false) {
                DFS(graph, graph[start][i], visited);
            }
        }
    }

    vector<int> dfs(vector<vector<int>> &adj) {
        int v = adj.size();
        vector<bool> visited(v, false);
        DFS(adj, 0, visited);
        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna