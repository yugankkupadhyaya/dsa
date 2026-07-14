class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1},
                                      {-1, -1}, {-1, 1}, {-1, 0}};


bool isValid(int row, int col, vector<vector<int>>& grid) {
    return row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == 0;
}
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    typedef pair<int, pair<int, int>> pq;
    n = grid[0].size();
    m = grid.size();
    if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1)
        return -1;

    vector<vector<int>> res(m, vector<int>(n, INT_MAX));
    priority_queue<pq, vector<pq>, greater<pq>> q;

  q.push({1, {0, 0}});
res[0][0] = 1;

   while (!q.empty()) {
    auto curr = q.top();
    q.pop();

    int d = curr.first;
    int x = curr.second.first;
    int y = curr.second.second;

    if (d > res[x][y]) continue;

    for (auto &dir : directions) {
        int row = x + dir[0];
        int col = y + dir[1];

        if (isValid(row, col, grid) && d + 1 < res[row][col]) {
            res[row][col] = d + 1;
            q.push({d + 1, {row, col}});
        }
    }
}
    if(res[m-1][n-1]==INT_MAX)return -1 ;
    return res[m-1][n-1];
}
}
;