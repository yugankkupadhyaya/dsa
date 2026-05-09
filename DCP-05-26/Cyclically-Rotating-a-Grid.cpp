1class Solution {
2public:
3    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
4        int m = grid.size();
5        int n = grid[0].size();
6
7        int layers = min(m, n) / 2;
8
9        for (int layer = 0; layer < layers; layer++) {
10
11            int top = layer;
12            int bottom = m - layer - 1;
13            int left = layer;
14            int right = n - layer - 1;
15
16            vector<int> arr;
17
18            // top row
19            for (int j = left; j <= right; j++) {
20                arr.push_back(grid[top][j]);
21            }
22
23            // right column
24            for (int i = top + 1; i <= bottom; i++) {
25                arr.push_back(grid[i][right]);
26            }
27
28            // bottom row
29            for (int j = right - 1; j >= left; j--) {
30                arr.push_back(grid[bottom][j]);
31            }
32
33            // left column
34            for (int i = bottom - 1; i > top; i--) {
35                arr.push_back(grid[i][left]);
36            }
37
38            int sz = arr.size();
39            int rot = k % sz;
40
41            vector<int> rotated(sz);
42
43            for (int i = 0; i < sz; i++) {
44                rotated[i] = arr[(i + rot) % sz];
45            }
46
47            int idx = 0;
48
49            // top row
50            for (int j = left; j <= right; j++) {
51                grid[top][j] = rotated[idx++];
52            }
53
54            // right column
55            for (int i = top + 1; i <= bottom; i++) {
56                grid[i][right] = rotated[idx++];
57            }
58
59            // bottom row
60            for (int j = right - 1; j >= left; j--) {
61                grid[bottom][j] = rotated[idx++];
62            }
63
64            // left column
65            for (int i = bottom - 1; i > top; i--) {
66                grid[i][left] = rotated[idx++];
67            }
68        }
69
70        return grid;
71    }
72};