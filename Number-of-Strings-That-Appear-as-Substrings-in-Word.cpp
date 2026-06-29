1class Solution {
2public:
3    int numOfStrings(vector<string>& patterns, string word) {
4        int count = 0;
5
6        for (string &pattern : patterns) {
7            if (word.find(pattern) != string::npos)
8                count++;
9        }
10
11        return count;
12    }
13};