class Solution {
public:

int n;
  vector<vector<int>>dp;
;

    bool isPredecessor(string s1, string s2) {
        if (s1.length() + 1 != s2.length())
            return false;

        int i = 0;
        int j = 0;

        while (i < s1.length() && j < s2.length()) {

            if (s1[i] == s2[j]) {
                i++;
            }

            j++;
        }

        return i == s1.length();
    }
    
    int solve(int prev, int curr, vector<string>& words) {

        if (curr >= n) {
            return 0;
        }
        if(dp[prev+1][curr]!=-1)return dp[prev+1][curr];



        int take = 0;

        // Don't take current word
        int nottake = solve(prev, curr + 1, words);

        // Take current word
        if (prev == -1 || isPredecessor(words[prev], words[curr])) {
            take = 1 + solve(curr, curr + 1, words);
        }

        return dp[prev+1][curr]= max(take, nottake);
    }
    int longestStrChain(vector<string>& words) {

        sort(words.begin(), words.end(),
             [](string& a, string& b) { return a.length() < b.length(); });

        n = words.size();
dp.resize(n+1,vector<int>(n+1,-1));
        return solve(-1, 0, words);
    }
};