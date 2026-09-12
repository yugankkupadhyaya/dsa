class Solution {
public:
    int n;
    vector<vector<pair<int, int>>> dp;

    pair<int, int> solve(int idx, int prev, vector<int>& nums) {

        if (idx == n)
            return {0, 1};

        // prev + 1 because prev can be -1
        if (dp[prev + 1][idx].first != -1)
            return dp[prev + 1][idx];

        pair<int, int> nottake = solve(idx + 1, prev, nums);

        pair<int, int> take = {0, 0};

        if (prev == -1 || nums[idx] > nums[prev]) {
            take = solve(idx + 1, idx, nums);
            take.first++;
        }

        if (take.first > nottake.first)
            return dp[prev + 1][idx] = take;

        if (nottake.first > take.first)
            return dp[prev + 1][idx] = nottake;

        return dp[prev + 1][idx] =
            {take.first, take.second + nottake.second};
    }

    int findNumberOfLIS(vector<int>& nums) {

        n = nums.size();

        dp.resize(
            n + 1,
            vector<pair<int, int>>(n + 1, {-1, -1})
        );

        auto ans = solve(0, -1, nums);

        return ans.second;
    }
};