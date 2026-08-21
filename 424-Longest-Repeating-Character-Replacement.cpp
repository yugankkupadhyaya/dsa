class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0};

        int right = 0;
        int n = s.size();
        int left = 0;

        int maxfreq = 0;
        int ans = 0;

        while (right < n) {

            freq[s[right] - 'A']++;

            maxfreq = max(maxfreq, freq[s[right] - 'A']);

            while (right - left + 1 - maxfreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            ans = max(ans, right - left + 1);

            right++;
        }

        return ans;
    }
};