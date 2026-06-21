class Solution {
public:
    int finder(int ind, int holding, vector<int>& prices,
               vector<vector<int>>& dp) {

        if (ind >= prices.size())
            return 0;

        if (dp[ind][holding] != -1)
            return dp[ind][holding];

        int skip = finder(ind + 1, holding, prices, dp);

        if (holding == 0) {
            int buy = -prices[ind] + finder(ind + 1, 1, prices, dp);
            return dp[ind][holding] = max(skip, buy);
        }
        else {
            int sell = prices[ind] + finder(ind + 2, 0, prices, dp);
            return dp[ind][holding] = max(skip, sell);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return finder(0, 0, prices, dp);
    }
};