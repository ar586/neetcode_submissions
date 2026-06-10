class Solution {
public:
    void finder(int ind, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans) {
        ans.push_back(temp);
        for (int i = ind; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            finder(i + 1, nums, temp, ans);
            temp.pop_back();
        }
    }
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        finder(0, nums, temp, ans);
        int sum=0;
        for(int i=0;i<ans.size();i++){
            int temp=0;
            for(int j=0;j<ans[i].size();j++){
                temp=temp^ans[i][j];
            }
            sum+=temp;
        }
        return sum;
    }
};