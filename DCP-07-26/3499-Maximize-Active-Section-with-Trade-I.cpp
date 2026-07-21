class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int active = 0;
        for (char c : s)
            if (c == '1') active++;

        string t = "1" + s + "1";

        vector<char> ch;
        vector<int> len;

        for (char c : t) {
            if (ch.empty() || ch.back() != c) {
                ch.push_back(c);
                len.push_back(1);
            } else {
                len.back()++;
            }
        }

        int ans = active;

        for (int i = 1; i + 1 < (int)ch.size(); i++) {
            if (ch[i] == '1' && ch[i - 1] == '0' && ch[i + 1] == '0') {
                ans = max(ans, active + len[i - 1] + len[i + 1]);
            }
        }

        return ans;
    }
};