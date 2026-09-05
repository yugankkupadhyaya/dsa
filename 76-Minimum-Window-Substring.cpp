class Solution {
public:
    string minWindow(string s, string t) {
        int count = t.size();

        int n = t.size();
        int m = s.size();

        if (n > m)
            return "";

        unordered_map<char, int> freq;

        for (char ch : t) {
            freq[ch]++;
        }

        int i = 0;
        int j = 0;
        int win = INT_MAX;
        int start = 0;

        while (j < m) {

            char ch = s[j];

            if (freq[ch] > 0) {
                count--;
            }

            freq[ch]--;

            while (count == 0) {

                int currwin = j - i + 1;

                if (currwin < win) {
                    win = currwin;
                    start = i;
                }

                freq[s[i]]++;

                if (freq[s[i]] > 0) {
                    count++;
                }

                i++;
            }

            j++;
        }

        if (win == INT_MAX)
            return "";

        return s.substr(start, win);
    }
};