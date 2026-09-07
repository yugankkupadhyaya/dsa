class Solution {
public:
    int n;

    int solve(int idx, vector<int>& cost, vector<int>& dp) {
        if (idx >= n) {
            return 0;
        }

        if (dp[idx] != -1)
            return dp[idx];

        int jump1 = solve(idx + 1, cost, dp);
        int jump2 = solve(idx + 2, cost, dp);

        return dp[idx] = min(jump1, jump2) + cost[idx];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();

        vector<int> dp(n, -1);

        return min(solve(0, cost, dp),
                   solve(1, cost, dp));
    }
};