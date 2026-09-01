class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        int litterCount = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        // Find S and assign each L an id.
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (classroom[r][c] == 'S') {
                    sr = r;
                    sc = c;
                }

                if (classroom[r][c] == 'L') {
                    id[r][c] = litterCount++;
                }
            }
        }

        int fullMask = (1 << litterCount) - 1;

        /*
            best[r][c][mask] = maximum energy with which
            we have reached (r, c) having collected mask.
        */

        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(
                n,
                vector<int>(1 << litterCount, -1)
            )
        );

        // r, c, mask, remaining energy
        queue<array<int, 4>> q;

        q.push({sr, sc, 0, energy});
        best[sr][sc][0] = energy;

        int moves = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [r, c, mask, currEnergy] = q.front();
                q.pop();

                // All litter collected.
                if (mask == fullMask) {
                    return moves;
                }

                // No energy means we cannot make another move.
                if (currEnergy == 0) {
                    continue;
                }

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Outside grid.
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n) {
                        continue;
                    }

                    // Obstacle.
                    if (classroom[nr][nc] == 'X') {
                        continue;
                    }

                    int newEnergy = currEnergy - 1;
                    int newMask = mask;

                    // Collect litter.
                    if (classroom[nr][nc] == 'L') {
                        newMask |= (1 << id[nr][nc]);
                    }

                    // Reset energy.
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    /*
                        Dominance pruning:

                        If we've already reached this exact
                        (position, mask) with MORE energy,
                        this state is useless.
                    */
                    if (newEnergy <= best[nr][nc][newMask]) {
                        continue;
                    }

                    best[nr][nc][newMask] = newEnergy;

                    q.push({
                        nr,
                        nc,
                        newMask,
                        newEnergy
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};