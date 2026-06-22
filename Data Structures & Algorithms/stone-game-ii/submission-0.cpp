class Solution {
public:
    int finder(int start, int m, vector<int>& piles,
               vector<int>& prefix, vector<vector<int>>& dp) {

        if (start >= piles.size()) return 0;

        if (dp[start][m] != -1) return dp[start][m];

        int totalRemaining = prefix[piles.size()] - prefix[start];
        int maxi = 0;

        for (int x = 1; x <= 2 * m && start + x <= piles.size(); x++) {
            int opponent =
                finder(start + x, max(m, x), piles, prefix, dp);

            maxi = max(maxi, totalRemaining - opponent);
        }

        return dp[start][m] = maxi;
    }

    int stoneGameII(vector<int>& piles) {

        int n = piles.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + piles[i];
        }

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return finder(0, 1, piles, prefix, dp);
    }
};