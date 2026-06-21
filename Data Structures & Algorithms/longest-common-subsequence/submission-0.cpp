class Solution {
public:
    int finder(int ind1,int ind2,string &text1, string &text2,vector<vector<int>>&dp){
        if(ind1>=text1.size() || ind2>=text2.size()){
            return 0;
        }
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        int matched=0;
        if(text1[ind1]==text2[ind2]){
            matched=1+finder(ind1+1,ind2+1,text1,text2,dp);
        }
        int mov1=finder(ind1+1,ind2,text1,text2,dp);
        int mov2=finder(ind1,ind2+1,text1,text2,dp);
        int maxi=max(mov1,mov2);
        return dp[ind1][ind2]=max(maxi,matched);
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        return finder(0,0,text1,text2,dp);
    }
};
