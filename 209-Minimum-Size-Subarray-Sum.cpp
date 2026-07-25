class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int left = 0;
        int right = 0;
        int n = nums.size();
        int ans = INT_MAX;

        while (right < n) {
            sum = sum + nums[right];
            right++;
            while (sum >= target) {
                // shrink the window  ans = min(ans, winsize);
                int winsize = right - left;
                ans = min(winsize, ans);
                sum -= nums[left];
                left++;
            }
        }
        if(ans==INT_MAX)return 0;
        return ans;
    }
};