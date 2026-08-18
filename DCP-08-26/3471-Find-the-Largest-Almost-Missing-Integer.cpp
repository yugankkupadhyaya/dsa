class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> count;

        int left = 0;
        int right = k - 1;

        while (right < n) {

            // New set for every window
            unordered_set<int> seen;

            // Put unique elements of current window into seen
            for (int i = left; i <= right; i++) {
                seen.insert(nums[i]);
            }

            // Each unique element appeared in this window
            for (int x : seen) {
                count[x]++;
            }

            // Slide window
            left++;
            right++;
        }

        int ans = -1;

        for (auto [x, freq] : count) {
            if (freq == 1) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};