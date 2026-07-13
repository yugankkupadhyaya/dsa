class Solution {
public:
    int n, m;
    bool isValid(int row, int col) {
        return row < m && row >= 0 && col < n && col >= 0;
    }

    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        queue<pair<int, int>> q;
       for (int i = 0; i < m; i++) {
    if (board[i][0] == 'O') {
        q.push({i, 0});
        board[i][0] = '#';
    }

    if (board[i][n - 1] == 'O') {
        q.push({i, n - 1});
        board[i][n - 1] = '#';
    }
}

for (int i = 0; i < n; i++) {
    if (board[0][i] == 'O') {
        q.push({0, i});
        board[0][i] = '#';
    }

    if (board[m - 1][i] == 'O') {
        q.push({m - 1, i});
        board[m - 1][i] = '#';
    }
}

        while (!q.empty()) {

            auto node = q.front();
            q.pop();
            int row = node.first;
            int col = node.second;

            for (int k = 0; k < 4; k++) {
                int i = row + x[k];
                int j = col + y[k];
                if (isValid(i, j) && board[i][j] == 'O') {
                    board[i][j] = '#';
                    q.push({i, j});
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == 'O') {
                    board[i][j] = 'X';

                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};