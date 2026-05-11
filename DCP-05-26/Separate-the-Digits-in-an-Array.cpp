1class Solution {
2public:
3    vector<int> separateDigits(vector<int>& nums) {
4        vector<int> ans;
5
6        for (int num : nums) {
7            string s = to_string(num);
8
9            for (char ch : s) {
10                ans.push_back(ch - '0');
11            }
12        }
13
14        return ans;
15    }
16};