class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int sx = -1, sy = -1;
        int litter_count = 0;
        
        // Map litter to specific bit indices for our bitmask
        int litter_id[25][25];
        memset(litter_id, -1, sizeof(litter_id));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                } else if (classroom[i][j] == 'L') {
                    litter_id[i][j] = litter_count++;
                }
            }
        }

        // All litter pieces collected
        int target_mask = (1 << litter_count) - 1;
        if (target_mask == 0) return 0;

        // DP array to prune sub-optimal paths: bestEnergy[x][y][mask]
        int bestEnergy[20][20][1024];
        memset(bestEnergy, -1, sizeof(bestEnergy));

        // Queue stores: {x, y, bitmask, remaining_energy}
        queue<tuple<int, int, int, int>> q;
        q.push({sx, sy, 0, energy});
        bestEnergy[sx][sy][0] = energy;

        int steps = 0;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y, mask, e] = q.front();
                q.pop();

                // If all litter is collected, we are done
                if (mask == target_mask) return steps;

                // Cannot move further if energy is depleted
                if (e == 0) continue;

                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    // Check boundaries and obstacles
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && classroom[nx][ny] != 'X') {
                        int nmask = mask;
                        
                        if (litter_id[nx][ny] != -1) {
                            nmask |= (1 << litter_id[nx][ny]);
                        }

                        int ne = e - 1;
                        if (classroom[nx][ny] == 'R') {
                            ne = energy; // Reset energy 
                        }

                        // Pruning: Only proceed if this path leaves us with strictly more energy
                        if (ne > bestEnergy[nx][ny][nmask]) {
                            bestEnergy[nx][ny][nmask] = ne;
                            q.push({nx, ny, nmask, ne});
                        }
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};