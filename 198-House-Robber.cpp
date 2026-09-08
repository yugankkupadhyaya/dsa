class Solution {
public:
    int n;
    int solve(int idx, vector<int>& dp,vector<int>& nums) {
        if (idx >= n)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int nottake = solve(idx + 1, dp,nums) + 0;
        int take = solve(idx + 2,dp,nums) + nums[idx];

        return dp[idx] = max(take, nottake);
    }

    int rob(vector<int>& nums) {
        n = nums.size();

        vector<int> dp(n + 1, -1);
        return solve(0, dp,nums);
    }
};