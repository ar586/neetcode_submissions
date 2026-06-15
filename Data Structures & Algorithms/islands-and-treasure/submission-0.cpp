class Solution {
   public:
    int bfs(int startRow, int startCol, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        q.push({startRow, startCol});
        visited[startRow][startCol] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int distance = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto [row, col] = q.front();
                q.pop();

                if (grid[row][col]==0) return distance;

                for (int k = 0; k < 4; k++) {
                    int nr = row + dr[k];
                    int nc = col + dc[k];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] &&
                        grid[nr][nc] !=-1) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }

            distance++;
        }

        return -1;
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2147483647) {
                    int temp = bfs(i, j, grid);
                    if (temp != -1) {
                        grid[i][j] = temp;
                    }
                }
            }
        }
    }
};
