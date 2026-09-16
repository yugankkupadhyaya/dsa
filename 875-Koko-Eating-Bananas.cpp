class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = 0;
        int low = 1;

        for (int a : piles) {
            high = max(a, high);
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;

            double hours = 0;

            for (int a : piles) {
                hours += (a + mid - 1) / mid;
            }

            if (hours <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};