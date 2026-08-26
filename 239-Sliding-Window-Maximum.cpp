class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> dq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {

            // Remove elements that are outside the window
            while (!dq.empty() && dq.front().second <= i - k) {
                dq.pop_front();
            }

            // Remove smaller elements from the back
            while (!dq.empty() && dq.back().first <= nums[i]) {
                dq.pop_back();
            }

            // Add current element
            dq.push_back({nums[i], i});

            // Window is ready
            if (i >= k - 1) {
                ans.push_back(dq.front().first);
            }
        }

        return ans;
    }
};