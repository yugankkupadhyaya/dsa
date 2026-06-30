1class Solution {
2public:
3    int numberOfSubstrings(string s) {
4        int n = s.size();
5
6        vector<int> freq(3, 0);
7
8        int l = 0;
9        int ans = 0;
10
11        for (int r = 0; r < n; r++) {
12
13            freq[s[r] - 'a']++;
14
15            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
16
17                ans += (n - r);
18
19                freq[s[l] - 'a']--;
20                l++;
21            }
22        }
23
24        return ans;
25    }
26};