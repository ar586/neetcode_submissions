class Solution {
public:
    int finder(int ind, vector<int>& cost, vector<int>& dp) {

        if (ind == 0) return cost[0];
        if (ind == 1) return cost[1];

        if (dp[ind] != -1) return dp[ind];

        int onestep = cost[ind] + finder(ind - 1, cost, dp);
        int twostep = cost[ind] + finder(ind - 2, cost, dp);

        return dp[ind] = min(onestep, twostep);
    }

    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();
        vector<int> dp(n, -1);

        return min(finder(n - 1, cost, dp),
                   finder(n - 2, cost, dp));
    }
};