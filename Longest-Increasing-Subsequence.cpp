1class Solution {
2public:
3    int n;
4    vector<vector<int>> dp;
5
6    int solve(int i, int p, vector<int>& nums) {
7        // base case
8        if (i >= n)
9            return 0;
10
11        // shifting p by +1 because p can be -1
12        if (dp[i][p + 1] != -1)
13            return dp[i][p + 1];
14
15        int take = 0;
16
17        // take only if valid LIS condition
18        if (p == -1 || nums[i] > nums[p]) {
19            take = 1 + solve(i + 1, i, nums);
20        }
21
22        int skip = solve(i + 1, p, nums);
23
24        return dp[i][p + 1] = max(take, skip);
25    }
26
27    int lengthOfLIS(vector<int>& nums) {
28        n = nums.size();
29
30        dp.resize(n, vector<int>(n + 1, -1));
31
32        return solve(0, -1, nums);
33    }
34};