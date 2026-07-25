class Solution {
public:
    int n;

    bool solve(int idx, vector<int>& nums,  vector<vector<int>> &dp, int target) {
        if (target == 0) {
            return true;
        }
        if (idx == n || target < 0) {
            return false;
        }
        if (dp[idx][target] != -1)
            return dp[idx][target];
        // take  case

        bool take = solve(idx + 1, nums, dp, target - nums[idx]);
        // backltrack

        bool notake = solve(idx + 1, nums, dp, target);
        return dp[idx][target] =take || notake;
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int totalsum = 0;
        for (int num : nums) {
            totalsum += num;
        }
        if (totalsum % 2 != 0)
            return false;

        int target = totalsum / 2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return solve(0, nums, dp, target);
    }
};