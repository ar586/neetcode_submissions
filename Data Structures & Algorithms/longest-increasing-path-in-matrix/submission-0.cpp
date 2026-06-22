class Solution {
   public:
    int finder(int i, int j, vector<vector<int>>& matrix,vector<vector<int>>&dp) {
        if (i < 0 || i > matrix.size() || j < 0 || j > matrix[0].size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi = 0;
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];

            if (nr >= 0 && nr < matrix.size() && nc >= 0 && nc < matrix[0].size() && matrix[i][j] < matrix[nr][nc]) {
                maxi = max(maxi, 1 + finder(nr, nc, matrix,dp));
            }
        }
        return dp[i][j]=maxi;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxi = 0;
        vector<vector<int>>dp(matrix.size()+1,vector<int>(matrix[0].size()+1,-1));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                int temp = finder(i, j, matrix,dp);
                maxi = max(maxi, 1+temp);
            }
        }
        return maxi;
    }
};
