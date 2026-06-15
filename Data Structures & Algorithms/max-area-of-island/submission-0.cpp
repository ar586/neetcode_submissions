class Solution {
   public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& v, int& count) {
        if (v[i][j] == 1) {
            return;
        }
        v[i][j] = 1;
        count++;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int k = 0; k < 4; k++) {
            int newRow = i + dr[k];
            int newCol = j + dc[k];
            if (newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() &&
                grid[newRow][newCol] == 1) {
                dfs(newRow, newCol, grid, v, count);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> v(n, vector<int>(m, 0));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int count = 0;
                if (v[i][j] == 1 || grid[i][j] == 0) continue;
                dfs(i, j, grid, v, count);
                ans = max(ans, count);
            }
        }
        return ans;
    }
};
