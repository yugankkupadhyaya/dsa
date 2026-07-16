class Solution {
public:
    bool checkValidString(string s) {
        int min = 0, max = 0;
        int n = s.size();
        for (char i : s) {

            if (i == '(') {
                min++, max++;
            }
            if (i == ')') {
                min--, max--;

            }
            else {
                min--;
                max++;
            }
            if (min < 0) {
                min = 0;
            }
            if (max < 0)
                return false;
        }
        return (min == 0);
    }
};