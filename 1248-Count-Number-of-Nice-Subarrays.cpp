class Solution {
public:
   int atmost(vector<int>& nums, int k){
        int n = nums.size();

        int left = 0;
        int count = 0;
        int oddcnt = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] % 2 == 1) {
                oddcnt++;
            }
            while (oddcnt > k) {
                if (nums[left] % 2 == 1) {
                    oddcnt--;
                }
                left++;
            }
            // keep counting the atmost arays wiht this
            count += right - left + 1;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {

        return atmost(nums, k) - atmost(nums, k - 1);
    }
};