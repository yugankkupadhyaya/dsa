class Solution {
public:
    static const int MOD = 1e9 + 7;

    int numberOfSets(int n, int k) {
        vector<vector<long long>> dp(n, vector<long long>(k + 1));

        for (int i = 0; i < n; i++)
            dp[i][0] = 1;

        for (int j = 1; j <= k; j++) {
            long long sum = 0;

            for (int i = 1; i < n; i++) {

                // Add possibilities where the previous segment
                // ends at or before i-1.
                sum = (sum + dp[i - 1][j - 1]) % MOD;

                // Either:
                // 1. Don't use point i as the right endpoint
                // 2. End a segment at i
                dp[i][j] = (dp[i - 1][j] + sum) % MOD;
            }
        }

        return dp[n - 1][k];
    }
};