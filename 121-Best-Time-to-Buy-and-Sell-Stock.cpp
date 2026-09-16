class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> minarr(prices.size());

        minarr[0] = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            minarr[i] = min(minarr[i - 1], prices[i]);
        }

        int profit = 0;

        for (int i = 0; i < prices.size(); i++) {
            profit = max(profit, prices[i] - minarr[i]);
        }

        return profit;
    }
};