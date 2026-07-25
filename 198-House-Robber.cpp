class Solution {
public:
    int n;

   int solve( int idx, vector<int>& nums, vector<int>& dp) {
        if (idx >= n) {
            return 0;
        }
        if (dp[idx] != -1)
            return dp[idx];

        int take =nums[idx] +solve(idx + 2, nums, dp);
        int nottake = solve(idx + 1, nums, dp);
        return dp[idx]=max(take,nottake);
    }

    int rob(vector<int>& nums) {
         n = nums.size();

        vector<int> dp(n, -1);
         solve(0,nums,dp);
         return dp[0];
    }
};