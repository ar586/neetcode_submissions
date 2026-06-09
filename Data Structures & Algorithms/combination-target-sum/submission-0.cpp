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
            temp.push_back(nums[i]);
            finder(i, nums, target - nums[i], temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        finder(0, nums, target, temp, ans);
        return ans;
    }
};