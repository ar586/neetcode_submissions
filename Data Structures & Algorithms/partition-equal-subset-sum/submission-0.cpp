class Solution {
public:
    bool finder(int ind, int target, vector<int>& nums,
                vector<vector<int>>& dp) {

        if (target == 0)
            return true;

        if (ind >= nums.size())
            return false;

        if (dp[ind][target] != -1)
            return dp[ind][target];

        bool take = false;
        if (nums[ind] <= target)
            take = finder(ind + 1, target - nums[ind], nums, dp);

        bool nottake = finder(ind + 1, target, nums, dp);

        return dp[ind][target] = take || nottake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int x : nums)
            sum += x;

        if (sum % 2)
            return false;

        int target = sum / 2;
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return finder(0, target, nums, dp);
    }
};
