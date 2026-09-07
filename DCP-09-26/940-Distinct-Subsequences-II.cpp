class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        // dp[i] = number of distinct subsequences including empty
        // after processing first i characters.
        vector<long long> dp(s.size() + 1, 0);
        dp[0] = 1;

        // last[c] = dp value before the previous occurrence of c
        vector<long long> last(26, 0);

        for (int i = 1; i <= s.size(); i++) {
            int c = s[i - 1] - 'a';

            dp[i] = (2 * dp[i - 1] - last[c] + MOD) % MOD;

            last[c] = dp[i - 1];
        }

        // Remove the empty subsequence
        return (dp[s.size()] - 1 + MOD) % MOD;
    }
};