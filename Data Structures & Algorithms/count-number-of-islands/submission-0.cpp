class Solution {
   public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& v) {
        if (v[i][j] == 1) {
            return;
        }
        v[i][j] = 1;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int k = 0; k < 4; k++) {
            int newRow = i + dr[k];
            int newCol = j + dc[k];
            if (newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol]-'0'==1) {
             dfs(newRow,newCol,grid,v);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> v(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == 1 || grid[i][j]-'0'==0) continue;
                ans++;
                dfs(i,j,grid,v);
            }
        }
        return ans;
    }
};
