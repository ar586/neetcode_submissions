class Solution {
public:
    int finder(int i,int j,int n,int m,vector<vector<int>>& grid, vector<vector<int>>&dp){
        if(i==n-1 && j==m-1){
            return grid[i][j];
        }
        if(i>=n || j>=m) return 100000;
        if(dp[i][j]!=-1) return dp[i][j];
        int right=grid[i][j]+finder(i+1,j,n,m,grid,dp);
        
        int left=grid[i][j]+finder(i,j+1,n,m,grid,dp);
       
        return dp[i][j]=min(right,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return finder(0,0,n,m,grid,dp);
    }
};