class Solution {
public:

    vector<vector<int>>dp;
    bool solve(int i, int j, int k, string s1, string s2, string s3) {
        if (k == s3.size()) {
            return i == s1.size() && j == s2.size();
        }

        int take1 = false;
        int take2 = false;
if(dp[i][j]!=-1 )    return dp[i][j];
        if (i < s1.size() && s1[i] == s3[k]) {
            take1 = solve(i + 1, j, k + 1, s1, s2, s3);
        }
        if (j < s2.size() && s2[j] == s3[k]) {
            take2 = solve(i, j + 1, k + 1, s1, s2, s3);
        }
        return dp[i][j]= take1 || take2;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() < s1.size() + s2.size())
            return false;
            dp.resize( s1.size()+1,vector<int>(s2.size()+1,-1));
        return solve(0, 0, 0, s1, s2, s3);
    }
};