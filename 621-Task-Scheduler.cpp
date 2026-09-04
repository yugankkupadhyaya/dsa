class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<char> ans;

        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> freq;

        for (char elem : tasks) {
            freq[elem]++;
        }
        unordered_map<char, int> nextAvailable;
        for (auto elem : freq) {
            pq.push({elem.second, elem.first});
            nextAvailable[elem.first] = 0;
        }
        int idx = 0;

        while (!pq.empty()) {

            vector<pair<int, char>> waiting;
            while (!pq.empty() && nextAvailable[pq.top().second] > idx) {
                waiting.push_back(pq.top());
                pq.pop();
            }

            if (pq.empty()) {
                ans.push_back('_');

            } else {
                auto node = pq.top();
                pq.pop();
                int count = node.first;
                char task = node.second;
                if (nextAvailable[task] <= idx) {
                    ans.push_back(task);
                     nextAvailable[task] = idx + n + 1;
                    count--;
                    if (count > 0) {

                        pq.push({count, task});
                    }
                }
            }

            for (auto elem : waiting) {
                pq.push(elem);
            }

            idx++;
        }
        return ans.size();
    }
};