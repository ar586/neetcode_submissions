class Solution {
public:
    int finder(int ind,int target,vector<int>& coins,vector<vector<int>>&dp){
        if(ind>=coins.size()) return 0;
        if(target<0) return 0;
        if(target==0) return 1;
        if(dp[ind][target]!=-1) return dp[ind][target];
        int take=finder(ind,target-coins[ind],coins,dp);
        int skip=finder(ind+1,target,coins,dp);
        return dp[ind][target]=skip+take;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        return finder(0,amount,coins,dp);
    }
};
