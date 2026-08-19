#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // Map row number -> set of reserved seats in that row
        unordered_map<int, unordered_set<int>> map;

        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 9) {
                map[row].insert(col);
            }
        }

        // Baseline: assume all n rows can fit 2 groups
        int totalGroups = n * 2;

        for (const auto& [row, reserved] : map) {
            totalGroups -= 2; // Subtract the 2 default groups for this row

            bool leftFree = !reserved.count(2) && !reserved.count(3) && 
                            !reserved.count(4) && !reserved.count(5);
            bool rightFree = !reserved.count(6) && !reserved.count(7) && 
                             !reserved.count(8) && !reserved.count(9);
            bool middleFree = !reserved.count(4) && !reserved.count(5) && 
                              !reserved.count(6) && !reserved.count(7);

            if (leftFree && rightFree) {
                totalGroups += 2;
            } else if (leftFree || rightFree || middleFree) {
                totalGroups += 1;
            }
        }

        return totalGroups;
    }
};