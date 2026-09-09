class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int i, int amount, vector<int>& coins) {

        if (amount == 0)
            return 1;

        if (i == n)
            return 0;

        if (dp[i][amount] != -1)
            return dp[i][amount];

        if (coins[i] > amount) {
            return dp[i][amount] =
                solve(i + 1, amount, coins);
        }

        int take = solve(i, amount - coins[i], coins);

        int skip = solve(i + 1, amount, coins);

        return dp[i][amount] = take + skip;
    }

    int change(int amount, vector<int>& coins) {

        n = coins.size();

        dp.assign(n, vector<int>(amount + 1, -1));

        return solve(0, amount, coins);
    }
};