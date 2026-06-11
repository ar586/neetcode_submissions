class Solution {
   public:
    bool solve(int start, int currSum, int k, vector<int>& nums, vector<bool>& used, int target) {
        if (k == 1) return true;
        if (currSum == target) return solve(0, 0, k - 1, nums, used, target);
        for (int i = start; i < nums.size(); i++) {
            if (used[i]) continue;
            if (currSum + nums[i] > target) continue;
            used[i] = true;
            if (solve(i + 1, currSum + nums[i], k, nums, used, target)) return true;
            used[i] = false;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int x : nums) sum += x;
        if (sum % k != 0) return false;
        int target = sum / k;
        vector<bool> used(nums.size(), false);
        return solve(0, 0, k, nums, used, target);
    }
};