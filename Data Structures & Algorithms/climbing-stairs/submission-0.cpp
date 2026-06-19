class Solution {
public:
    int finder(int ind,vector<int>&memo){
        if(ind<0){
         return 0;
        }
        if(ind==0){
            return 1;
        }
        if(memo[ind]!=-1) return memo[ind];
        int onestep=finder(ind-1,memo);
        int twostep=finder(ind-2,memo);
        return memo[ind]= onestep+twostep;
    }
    int climbStairs(int n) {
        vector<int>memo(n+1,-1);
        return finder(n,memo);
    }
};
