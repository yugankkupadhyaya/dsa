1class Solution {
2public:
3    int minimumEffort(vector<vector<int>>& tasks) {
4
5        sort(tasks.begin(), tasks.end(),
6             [](vector<int>& a, vector<int>& b) {
7
8            return (a[1] - a[0]) > (b[1] - b[0]);
9        });
10
11        int ans = 0;
12        int curr = 0;
13
14        for (auto& t : tasks) {
15
16            int actual = t[0];
17            int minimum = t[1];
18
19            if (curr < minimum) {
20
21                ans += (minimum - curr);
22                curr = minimum;
23            }
24
25            curr -= actual;
26        }
27
28        return ans;
29    }
30};