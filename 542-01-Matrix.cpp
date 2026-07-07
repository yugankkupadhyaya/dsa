class Solution {
public:
    int n, m;

    bool isValid(int row, int col) {
        return row >= 0 && row < n && col >= 0 && col < m;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();

        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        // Push all 0s into the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = row + dx[k];
                int nc = col + dy[k];

                if (isValid(nr, nc) && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[row][col] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return dist;
    }
};