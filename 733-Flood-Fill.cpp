class Solution {
public:
    int m, n;
    int startColor;
    bool isValid(int row, int col) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    void dfs(vector<vector<int>>& image, int& row, int& col, int color) {
        image[row][col] = color;
        for (int k = 0; k < 4; k++) {
            int i = row + x[k];
            int j = col + y[k];

            if (isValid(i, j) && image[i][j] == startColor) {
                dfs(image, i, j, color);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        m = image.size();    // rows
        n = image[0].size(); // columns
        startColor = image[sr][sc];
        if (startColor == color)
            return image;
        dfs(image, sr, sc, color);
        return image;
    }
};