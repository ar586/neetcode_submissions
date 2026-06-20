class Solution {
public:
    int finder(int ind,int target,vector<vector<int>>& dp){
        if(target==0){
            return 0;
        }
        if(ind*ind>target || target<0){
            return 100000;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int take=1+finder(ind,target-(ind*ind),dp);
        int nottake=finder(ind+1,target,dp);
        return dp[ind][target]=min(take,nottake);

    }
    int numSquares(int n) {
        if(n==1) return 1;
         vector<vector<int>> dp(n, vector<int>(n + 1, -1));
       return finder(1,n,dp); 
    }
};