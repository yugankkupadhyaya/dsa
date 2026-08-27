class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> total(26, 0);
        for (char c : s) {
            total[c - 'a']++;
        }

        // prefixValid[i] means target[0 ... i-1]
        // can be formed using characters from s.
        vector<bool> prefixValid(n + 1, false);
        prefixValid[0] = true;

        vector<int> used(26, 0);

        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            if (used[x] < total[x]) {
                used[x]++;
                prefixValid[i + 1] = true;
            } else {
                break;
            }
        }

        // Try changing target[i], starting from the right.
        for (int i = n - 1; i >= 0; i--) {

            // The prefix target[0 ... i-1] must be possible.
            if (!prefixValid[i]) {
                continue;
            }

            // Characters remaining after using target[0 ... i-1].
            vector<int> remaining = total;

            for (int j = 0; j < i; j++) {
                remaining[target[j] - 'a']--;
            }

            int x = target[i] - 'a';

            // Find the smallest character > target[i].
            for (int c = x + 1; c < 26; c++) {

                if (remaining[c] > 0) {
                    string ans = target.substr(0, i);

                    // Make the first position where we differ larger.
                    ans += char('a' + c);
                    remaining[c]--;

                    // Fill the rest with the smallest possible characters.
                    for (int j = 0; j < 26; j++) {
                        while (remaining[j] > 0) {
                            ans += char('a' + j);
                            remaining[j]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};