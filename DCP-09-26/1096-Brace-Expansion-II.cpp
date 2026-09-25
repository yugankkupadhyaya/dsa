class Solution {
public:
    int i = 0;

    set<string> product(set<string>& a, set<string>& b) {
        set<string> res;

        for (string x : a) {
            for (string y : b) {
                res.insert(x + y);
            }
        }

        return res;
    }

    set<string> parse(string& s) {
        set<string> res = {""};

        while (i < s.size() && s[i] != '}' && s[i] != ',') {

            set<string> curr;

            if (s[i] == '{') {
                i++;              // skip '{'
                curr = parse();
                i++;              // skip '}'
            }
            else {
                curr.insert(string(1, s[i]));
                i++;
            }

            res = product(res, curr);
        }

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        set<string> ans;

        while (i < expression.size()) {

            set<string> curr = parse();

            for (string word : curr) {
                ans.insert(word);
            }

            if (i < expression.size() && expression[i] == ',') {
                i++;              // skip ','
            }
        }

        return vector<string>(ans.begin(), ans.end());
    }
};