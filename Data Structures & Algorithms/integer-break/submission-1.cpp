class Solution {
public:
    int finder(int ind,int target,vector<vector<int>>&dp){
        if(target==0){
            return 1;
        }
        if(target<0 || ind>target){
            return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int take=ind*finder(ind,target-ind,dp);
        int nottake=finder(ind+1,target,dp);
        return dp[ind][target]=max(take,nottake);
    }
    int integerBreak(int n) {
        if(n==2){
            return 1;
        }
        if(n==3){
            return 2;
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return finder(1,n,dp);
    }
};