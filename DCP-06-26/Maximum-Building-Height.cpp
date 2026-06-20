1class Solution {
2public:
3    int maxBuilding(int n, vector<vector<int>>& restrictions) {
4        restrictions.push_back({1, 0});
5
6        bool hasN = false;
7        for (auto &r : restrictions) {
8            if (r[0] == n) {
9                hasN = true;
10                break;
11            }
12        }
13
14        if (!hasN)
15            restrictions.push_back({n, n - 1});
16
17        sort(restrictions.begin(), restrictions.end());
18
19        int m = restrictions.size();
20
21        // Left -> Right
22        for (int i = 1; i < m; i++) {
23            restrictions[i][1] = min(
24                restrictions[i][1],
25                restrictions[i - 1][1] +
26                    (restrictions[i][0] - restrictions[i - 1][0])
27            );
28        }
29
30        // Right -> Left
31        for (int i = m - 2; i >= 0; i--) {
32            restrictions[i][1] = min(
33                restrictions[i][1],
34                restrictions[i + 1][1] +
35                    (restrictions[i + 1][0] - restrictions[i][0])
36            );
37        }
38
39        long long ans = 0;
40
41        for (int i = 1; i < m; i++) {
42            long long x1 = restrictions[i - 1][0];
43            long long h1 = restrictions[i - 1][1];
44
45            long long x2 = restrictions[i][0];
46            long long h2 = restrictions[i][1];
47
48            long long dist = x2 - x1;
49
50            long long peak = (h1 + h2 + dist) / 2;
51
52            ans = max(ans, peak);
53        }
54
55        return (int)ans;
56    }
57};