class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Check if a palindromic permutation is possible
        int odd = 0;
        char middle = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                middle = char('a' + i);
            }
        }

        if (odd > 1) {
            return "";
        }

        // Build character counts for the first half
        vector<int> halfCnt(26);

        for (int i = 0; i < 26; i++) {
            halfCnt[i] = cnt[i] / 2;
        }

        int m = n / 2;
        string targetHalf = target.substr(0, m);

        string half;
        vector<int> remaining = halfCnt;

        // Try to match target's first half
        for (int i = 0; i < m; i++) {
            int x = targetHalf[i] - 'a';

            if (remaining[x] > 0) {
                half += char('a' + x);
                remaining[x]--;
            } 
            else {
                // Try the smallest character greater than target[i]
                int bigger = -1;

                for (int c = x + 1; c < 26; c++) {
                    if (remaining[c] > 0) {
                        bigger = c;
                        break;
                    }
                }

                if (bigger != -1) {
                    half += char('a' + bigger);
                    remaining[bigger]--;

                    // Fill the rest as small as possible
                    for (int c = 0; c < 26; c++) {
                        while (remaining[c] > 0) {
                            half += char('a' + c);
                            remaining[c]--;
                        }
                    }

                    return makePalindrome(half, middle, n);
                }

                // Cannot continue, so we need to backtrack
                break;
            }
        }

        // We matched the entire target half
        if ((int)half.size() == m) {
            string candidate = makePalindrome(half, middle, n);

            // Candidate is already strictly greater
            if (candidate > target) {
                return candidate;
            }

            // Candidate == target, so find next permutation
            if (next_permutation(half.begin(), half.end())) {
                return makePalindrome(half, middle, n);
            }

            return "";
        }

        // Backtrack to find the rightmost position
        // that can be increased.
        while (!half.empty()) {
            int last = half.back() - 'a';
            half.pop_back();

            remaining[last]++;

            int pos = half.size();
            int targetChar = targetHalf[pos] - 'a';

            // Find smallest available character
            // greater than target[pos].
            for (int c = targetChar + 1; c < 26; c++) {
                if (remaining[c] > 0) {
                    half += char('a' + c);
                    remaining[c]--;

                    // Fill remaining positions minimally
                    for (int k = 0; k < 26; k++) {
                        while (remaining[k] > 0) {
                            half += char('a' + k);
                            remaining[k]--;
                        }
                    }

                    return makePalindrome(half, middle, n);
                }
            }
        }

        return "";
    }

private:
    string makePalindrome(
        const string& half,
        char middle,
        int n
    ) {
        string result = half;

        if (n % 2) {
            result += middle;
        }

        string rev = half;
        reverse(rev.begin(), rev.end());

        result += rev;

        return result;
    }
};