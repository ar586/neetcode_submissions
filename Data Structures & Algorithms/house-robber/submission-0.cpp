class Solution {
public:
    int finder(int ind,vector<int>& nums,vector<int>&memo){
        if(ind<0){
            return 0;
        }
        if(memo[ind]!=-1) return memo[ind];
        int take=nums[ind]+finder(ind-2,nums,memo);
        int ntake=finder(ind-1,nums,memo);
        return memo[ind]=max(take,ntake);
    }
    int rob(vector<int>& nums) {
        vector<int>memo(nums.size(),-1);
        return finder(nums.size()-1,nums,memo);
    }
};
