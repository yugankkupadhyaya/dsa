class Solution {
public:
    int findGCD(vector<int>& nums) {
        int b = INT_MAX;
        int a = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {

            b = min(b, nums[i]);
            a = max(a, nums[i]);
        }
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};