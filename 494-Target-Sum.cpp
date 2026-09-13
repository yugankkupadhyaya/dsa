class Solution {
public:
    int n;
    int offset;
    vector<vector<int>> dp;

    int solve(int idx, int target, vector<int>& nums) {

        if (idx == n)
            return target == 0;

        if (dp[idx][target + offset] != -1)
            return dp[idx][target + offset];

        int sub = solve(idx + 1, target - nums[idx], nums);

        int add = solve(idx + 1, target + nums[idx], nums);

        return dp[idx][target + offset] = sub + add;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        n = nums.size();

        int sum = 0;
        for (int a : nums)
            sum += a;

        offset = sum;

        if (target > sum || target < -sum)
            return 0;

        dp.resize(n, vector<int>(2 * offset + 1, -1));

        return solve(0, target, nums);
    }
};