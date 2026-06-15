class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> pq;

        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2)
                    pq.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int time = 0;

        while (!pq.empty() && fresh > 0) {
            int size = pq.size();

            for (int i = 0; i < size; i++) {
                auto [row, col] = pq.front();
                pq.pop();

                for (int k = 0; k < 4; k++) {
                    int nr = row + dr[k];
                    int nc = col + dc[k];

                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < m &&
                        grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;
                        fresh--;
                        pq.push({nr, nc});
                    }
                }
            }

            time++;
        }

        return (fresh == 0) ? time : -1;
    }
};
