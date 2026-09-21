class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> dp(k, 0);
        vector<long long> ans(k, 0);

        for (int num : nums) {
            vector<long long> ndp(k, 0);

            // Start a new subarray with only nums[i]
            ndp[num % k]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {
                int newRem = (r * (num % k)) % k;
                ndp[newRem] += dp[r];
            }

            // All subarrays ending here contribute to the answer
            for (int r = 0; r < k; r++) {
                ans[r] += ndp[r];
            }

            dp = ndp;
        }

        return ans;
    }
};