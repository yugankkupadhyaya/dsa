class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixGcd;
        prefixGcd.reserve(n);

        int mx = 0;

        for (int x : nums) {
            mx = max(mx, x);
            prefixGcd.push_back(std::gcd(x, mx));
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;

        int left = 0, right = n - 1;

        while (left < right) {
            ans += std::gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }

        return ans;
    }
};