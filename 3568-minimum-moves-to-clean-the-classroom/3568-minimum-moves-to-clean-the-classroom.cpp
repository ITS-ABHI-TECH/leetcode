class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        // Give every litter cell an index
        vector<vector<int>> id(m, vector<int>(n, -1));
        int litter = 0;

        int sx, sy;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = litter++;
                }
            }
        }

        int fullMask = (1 << litter) - 1;

        // best[i][j][mask] = maximum energy with which
        // we have reached (i,j) after collecting mask
        vector<vector<vector<int>>> best(
            m, vector<vector<int>>(n, vector<int>(1 << litter, -1))
        );

        queue<tuple<int, int, int, int>> q;

        // x, y, mask, remaining energy
        q.push({sx, sy, 0, energy});
        best[sx][sy][0] = energy;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [x, y, mask, en] = q.front();
                q.pop();

                if (mask == fullMask)
                    return moves;

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    // Outside classroom
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;

                    // Wall
                    if (classroom[nx][ny] == 'X')
                        continue;

                    // Moving costs 1 energy
                    int newEnergy = en - 1;

                    if (newEnergy < 0)
                        continue;

                    int newMask = mask;

                    // Collect litter
                    if (classroom[nx][ny] == 'L') {
                        newMask |= (1 << id[nx][ny]);
                    }

                    // Recharge
                    if (classroom[nx][ny] == 'R') {
                        newEnergy = energy;
                    }

                    // If energy becomes 0, we can only stop/recharge
                    // at R. We cannot make another move from here.
                    if (newEnergy == 0 && classroom[nx][ny] != 'R'
                        && newMask != fullMask) {
                        // We can still enter this cell, but it won't
                        // be useful unless all litter is collected.
                        continue;
                    }

                    // Already reached this state with >= energy
                    if (best[nx][ny][newMask] >= newEnergy)
                        continue;

                    best[nx][ny][newMask] = newEnergy;

                    q.push({nx, ny, newMask, newEnergy});
                }
            }

            moves++;
        }

        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna