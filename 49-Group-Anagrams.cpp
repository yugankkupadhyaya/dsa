class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;

        for (string str : strs) {

            string key = str;
            sort(key.begin(), key.end());
            mpp[key].push_back(str);
        }

        vector<vector<string>> res;
        for (auto val : mpp) {
            res.push_back(val.second);
        }
        return res;
    }
};