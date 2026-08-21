class Solution {
public:

    int atmost(int gol, vector<int>& nums) {

        if (gol < 0)
            return 0;

        int left = 0;
        int count = 0;
        int sum = 0;

        for (int right = 0; right < nums.size(); right++) {

            sum += nums[right];

            while (sum > gol) {
                sum -= nums[left];
                left++;
            }

            count += right - left + 1;
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        int mostgol = atmost(goal, nums);
        int mostbefore = atmost(goal - 1, nums);

        return mostgol - mostbefore;
    }
};