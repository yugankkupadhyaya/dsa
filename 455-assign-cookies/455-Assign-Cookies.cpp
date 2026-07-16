class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        // now we have the sorted arrays
        int count = 0;
        int kids = g.size();
        int choc = s.size();
        int i = 0, j = 0;
        while (i < kids && j < choc) {

            if (g[i] <=s[j]) {
                count++;
                i++;

                j++;

            } else {
                j++;
            }
        }
        return count;
    }
};