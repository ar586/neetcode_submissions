class Solution {
public:
    void finder(int ind,vector<int>&checker, vector<int>&temp,vector<vector<int>>&ans,vector<int>& nums){
        
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(checker[i]==1) continue;
            temp.push_back(nums[i]);
            checker[i]=1;
            finder(ind+1,checker,temp,ans,nums);
            temp.pop_back();
            checker[i]=0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>checker(nums.size(),0);
        vector<vector<int>>ans;
        vector<int>temp;
        finder(0,checker,temp,ans,nums);
        return ans;
    }
};
