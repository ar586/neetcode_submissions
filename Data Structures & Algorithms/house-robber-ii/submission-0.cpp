class Solution {
public:
    int finder(int ind, vector<int>& nums, vector<int>& memo) {
        if (ind < 0) return 0;

        if (memo[ind] != -1) return memo[ind];

        int take = nums[ind] + finder(ind - 2, nums, memo);
        int ntake = finder(ind - 1, nums, memo);

        return memo[ind] = max(take, ntake);
    }

    int finder2(int ind, vector<int>& nums, vector<int>& memo) {
        if (ind <= 0) return 0;  

        if (memo[ind] != -1) return memo[ind];

        int take = nums[ind] + finder2(ind - 2, nums, memo);
        int ntake = finder2(ind - 1, nums, memo);

        return memo[ind] = max(take, ntake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        vector<int> memo1(n, -1), memo2(n, -1);

        int excludeLast = finder(n - 2, nums, memo1);
        int excludeFirst = finder2(n - 1, nums, memo2);

        return max(excludeLast, excludeFirst);
    }
};
