class Solution {
public:

    int helper[200][200];
    int m, n;

    int x[4] = {-1, 0, 0, 1};
    int y[4] = {0, -1, 1, 0};

    bool isValid(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int solve(int i, int j, vector<vector<int>>& matrix) {

        // Already calculated
        if (helper[i][j] != 0)
            return helper[i][j];

        int ans = 1;

        for (int k = 0; k < 4; k++) {

            int ni = i + x[k];
            int nj = j + y[k];

            if (isValid(ni, nj) &&
                matrix[ni][nj] > matrix[i][j]) {

                ans = max(ans, 1 + solve(ni, nj, matrix));
            }
        }

        return helper[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        m = matrix.size();
        n = matrix[0].size();

        memset(helper, 0, sizeof(helper));

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                ans = max(ans, solve(i, j, matrix));
            }
        }

        return ans;
    }
};