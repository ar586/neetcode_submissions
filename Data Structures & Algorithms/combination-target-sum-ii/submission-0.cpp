class Solution {
public:
    void finder(int ind, vector<int>& nums, int target,
                vector<int>& temp, vector<vector<int>>& ans) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        if(ind >= nums.size() || target < 0)
            return;        
        for(int i = ind; i < nums.size(); i++) {
             if(i > ind && nums[i] == nums[i-1])
                continue;
            temp.push_back(nums[i]);            
            finder(i+1, nums, target - nums[i], temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        finder(0, nums, target, temp, ans);
        return ans;
    }
};
