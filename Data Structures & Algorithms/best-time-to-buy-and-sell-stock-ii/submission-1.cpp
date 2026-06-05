class Solution {
public:

    vector<vector<int>> dp;

    int finder(int ind, int bought, vector<int>& prices) {

        if (ind == prices.size()) {
            return 0;
        }

        if (dp[ind][bought] != -1) {
            return dp[ind][bought];
        }
        if (bought == 0) {

            int buy =
                -prices[ind] + finder(ind + 1, 1, prices);

            int skip =
                finder(ind + 1, 0, prices);

            return dp[ind][bought] = max(buy, skip);
        }
        int sell =
            prices[ind] + finder(ind + 1, 0, prices);

        int skip =
            finder(ind + 1, 1, prices);

        return dp[ind][bought] = max(sell, skip);
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        dp.resize(n, vector<int>(2, -1));

        return finder(0, 0, prices);
    }
};