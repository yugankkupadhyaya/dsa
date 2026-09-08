class Solution {
public:
    int n;
    vector<int> dp;

    int solve(int idx, string& s) {

        // Successfully decoded the entire string
        if (idx == n)
            return 1;

        // A number starting with 0 is invalid
        if (s[idx] == '0')
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        // Take one digit
        int ways = solve(idx + 1, s);

        // Take two digits if they form 10-26
        if (idx + 1 < n &&
            (s[idx] == '1' ||
             (s[idx] == '2' && s[idx + 1] <= '6'))) {

            ways += solve(idx + 2, s);
        }

        return dp[idx] = ways;
    }

    int numDecodings(string s) {

        n = s.size();
        dp.assign(n, -1);

        return solve(0, s);
    }
};