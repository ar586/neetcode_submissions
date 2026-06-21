class Solution {
public:
    int finder(int i,int j,int n,int m,vector<vector<int>>& grid, vector<vector<int>>&dp){
        if(i==n-1 && j==m-1){
            return 1;
        }
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int right=0;
        if(i+1<n && grid[i+1][j]==0){
            right=finder(i+1,j,n,m,grid,dp);
        }
        int left=0;
        if(j+1<m && grid[i][j+1]==0){
            left=finder(i,j+1,n,m,grid,dp);
        }
        return dp[i][j]=right+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]){
            return 0;
        }
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return finder(0,0,n,m,grid,dp);
    }
};