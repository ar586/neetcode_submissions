class Solution {
public:
    unordered_map<int, unordered_map<int, int>> dp;

    int finder(int ind, int sum, int target, vector<int>& nums) {
        if (ind == nums.size())
            return sum == target;

        if (dp[ind].count(sum))
            return dp[ind][sum];

        int add = finder(ind + 1, sum + nums[ind], target, nums);
        int sub = finder(ind + 1, sum - nums[ind], target, nums);

        return dp[ind][sum] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return finder(0, 0, target, nums);
    }
};