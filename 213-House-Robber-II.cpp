class Solution {
public:
    int n;
    vector<int> dp;

    int solve(int idx, int end, vector<int>& nums) {
        if (idx > end)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int take = nums[idx] + solve(idx + 2, end, nums);
        int notTake = solve(idx + 1, end, nums);

        return dp[idx] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        n = nums.size();

        if (n == 1)
            return nums[0];

        // Case 1: take from 0 to n-2
        dp.assign(n + 1, -1);
        int case1 = solve(0, n - 2, nums);

        // Case 2: take from 1 to n-1
        dp.assign(n + 1, -1);
        int case2 = solve(1, n - 1, nums);

        return max(case1, case2);
    }
};