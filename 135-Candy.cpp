class Solution {
public:
    int candy(vector<int>& ratings) {
        // track the slop of the
        int n = ratings.size();
        int sum = 1;

        int i = 1;
        while (i < n) {
            // now we will compare the slops
            if (i < n && ratings[i] == ratings[i - 1]) {
                sum += 1;
                i++;
            }
            int top = 0;
            while (i < n && ratings[i] > ratings[i - 1]) {
                top += 1;
                sum +=1+ top;
                i++;
            }
            int bottom = 0;
            while (i < n && ratings[i] < ratings[i - 1]) {
                bottom += 1;
                sum += bottom;
                i++;
            }
            if (bottom > top) {

                sum += bottom - top;
            }
            top = 1;
            bottom = 1;
        }
        return sum;
    }
};