class Solution {
public:
    // for checkint in 4 directions
    bool isValid(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    void check(int row, int col, vector<vector<int>>& grid,
               queue<pair<int, int>>& q, int &fresh, int m, int n, bool &rottedThisMinute) {
        for (int k = 0; k < 4; k++) {
            int i = row + x[k];
            int j = col + y[k];
            if (isValid(i, j, m, n)) {
                if (grid[i][j] == 1) {
                     grid[i][j] = 4;
                    fresh--;
                    q.push({i, j});
                   if( !rottedThisMinute){
                     rottedThisMinute=true;
                   }
                }
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int time = 0;
        int fresh = 0;
        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)  fresh++;
                   
              
            }
        }

        while (!q.empty()) {
            bool rottedThisMinute = false;
            int s = q.size();
            for (int i = 0; i < s; i++) {
                auto node = q.front();

                int row = node.first;
                int col = node.second;
                check(row, col, grid, q, fresh, m, n,rottedThisMinute);
                q.pop();
            }
         if( rottedThisMinute)   time++;
        }
        if (fresh != 0)
            return -1;
        return time;
    }
};