        class Solution {
        public:
            int maxSubarrayLength(vector<int>& nums, int k) {
                unordered_map<int, int> mpp;
                int n = nums.size();

                int left = 0;
                int ans = 0;
                for (int right = 0; right < n; right++) {
                    // push rhe curetn right elemnt
                    mpp[nums[right]]++;

                    while (mpp[nums[right]] > k) {
                        mpp[nums[left]]--;
                        left++;
                    }
                    ans = max(ans, right - left + 1);
                  
                }
                return ans;
            }
        };