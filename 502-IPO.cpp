class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        priority_queue<int> pq;
        // the format of storing will be {cost,profit}
        // declaring a 2d vector for stopring the cost and profit pair
        vector<pair<int, int>> a;
        for (int i = 0; i < capital.size(); i++) {
            a.push_back({capital[i], profits[i]});
        }
        sort(a.begin(), a.end());
        // now we will traverse the array a to
        int idx = 0;
        while (k--) {
            while (idx < a.size() && a[idx].first <= w) {
                  pq.push(a[idx].second);
                idx++;
            }
            if (pq.empty()) {
                return w;
            }
            // choose the best avail project here
            w += pq.top();
            pq.pop();
        }return w;
    }
};