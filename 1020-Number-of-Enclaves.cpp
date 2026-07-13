class Solution {
public:
    int m, n;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool isValid(int r, int c) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        queue<pair<int, int>> q;

        // Push all boundary land cells
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) {
                q.push({i, 0});
                grid[i][0] = 2;
            }

            if (grid[i][n - 1] == 1) {
                q.push({i, n - 1});
                grid[i][n - 1] = 2;
            }
        }

        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) {
                q.push({0, j});
                grid[0][j] = 2;
            }

            if (grid[m - 1][j] == 1) {
                q.push({m - 1, j});
                grid[m - 1][j] = 2;
            }
        }

        // Multi-source BFS
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dx[k];
                int nc = c + dy[k];

                if (isValid(nr, nc) && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                }
            }
        }

        // Count remaining land cells
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    ans++;
            }
        }

        return ans;
    }
};