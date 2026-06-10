class Solution {
   public:
    void finder(vector<int>& nums, vector<int>& temp, vector<int>& used, vector<vector<int>>& ans) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            temp.push_back(nums[i]);
            used[i] = 1;
            finder(nums, temp, used, ans);
            used[i] = 0;
            temp.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> used(nums.size(), 0);
        finder(nums, temp, used, ans);
        return ans;
    }
};