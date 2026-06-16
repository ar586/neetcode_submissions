class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<int>>& v, int ocean) {
        if (v[i][j] & ocean) {
            return;
        }

        v[i][j] |= ocean;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int newRow = i + dr[k];
            int newCol = j + dc[k];

            if (newRow >= 0 && newRow < heights.size() &&
                newCol >= 0 && newCol < heights[0].size() &&
                heights[newRow][newCol] >= heights[i][j]) {

                dfs(newRow, newCol, heights, v, ocean);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> v(n, vector<int>(m, 0));

        int i = 0;
        for (int j = 0; j < m; j++) {
            dfs(i, j, heights, v, 1);
        }

        int k = n - 1;
        for (int j = 0; j < m; j++) {
            dfs(k, j, heights, v, 2);
        }

        int p = 0;
        for (int t = 0; t < n; t++) {
            dfs(t, p, heights, v, 1);
        }

        int z = m - 1;
        for (int t = 0; t < n; t++) {
            dfs(t, z, heights, v, 2);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == 3) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
