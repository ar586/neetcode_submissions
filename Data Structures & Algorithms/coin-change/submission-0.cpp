class Solution {
public:
    int finder(int ind, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if (amount == 0)
            return 0;

        if (amount < 0 || ind >= coins.size())
            return INT_MAX;

        if (dp[ind][amount] != -1)
            return dp[ind][amount];

        int take = INT_MAX;
        int temp = finder(ind, coins, amount - coins[ind], dp);

        if (temp != INT_MAX)
            take = 1 + temp;

        int nottake = finder(ind + 1, coins, amount, dp);

        return dp[ind][amount] = min(take, nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        int ans = finder(0, coins, amount, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};
