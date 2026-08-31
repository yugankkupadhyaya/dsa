class Solution {
public:
    string reorganizeString(string s) {

        unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        priority_queue<pair<int, char>> maxHeap;

        for (auto it : freq) {
            maxHeap.push({it.second, it.first});
        }

        string s2;

        while (!maxHeap.empty()) {

            // Most frequent character
            auto node = maxHeap.top();
            maxHeap.pop();

            // Can't use same character consecutively
            if (!s2.empty() && s2.back() == node.second) {

                // No other character available
                if (maxHeap.empty()) {
                    return "";
                }

                // Take second most frequent character
                auto second = maxHeap.top();
                maxHeap.pop();

                s2 += second.second;
                second.first--;

                if (second.first > 0) {
                    maxHeap.push(second);
                }

                // Put the first character back
                maxHeap.push(node);

            } else {

                s2 += node.second;
                node.first--;

                if (node.first > 0) {
                    maxHeap.push(node);
                }
            }
        }

        return s2;
    }
};