class Solution {
public:
    int finder(int ind, vector<int>& stoneValue, vector<int>& dp) {
        if (ind >= stoneValue.size()) return 0;

        if (dp[ind] != INT_MIN) return dp[ind];

        int sum = 0;
        int maxi = INT_MIN;

        for (int i = 0; i < 3; i++) {
            if (ind + i < stoneValue.size()) {
                sum += stoneValue[ind + i];
                int take = sum - finder(ind + i + 1, stoneValue, dp);
                maxi = max(maxi, take);
            }
        }

        return dp[ind] = maxi;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size(), INT_MIN);

        int diff = finder(0, stoneValue, dp);

        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        return "Tie";
    }
};