class Solution {
public:
    int finder(int n,vector<int>&memo){
        if(n<=0){
            return 0;
        }
        if(n==1 || n==2){
            return 1;
        }
        if(memo[n]!=-1) return memo[n];
        return memo[n]=finder(n-1,memo)+finder(n-2,memo)+finder(n-3,memo);
    }
    int tribonacci(int n) {
       vector<int>memo(n+1,-1);
       return finder(n,memo); 
    }
};