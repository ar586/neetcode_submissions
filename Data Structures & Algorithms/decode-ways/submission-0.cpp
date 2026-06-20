class Solution {
public:
    int finder(int ind, string& s, vector<int>& dp) {
        if (ind == s.size())
            return 1;

        if (s[ind] == '0')
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        int ans = finder(ind + 1, s, dp);

        if (ind + 1 < s.size()) {
            int num = stoi(s.substr(ind, 2));
            if (num >= 10 && num <= 26)
                ans += finder(ind + 2, s, dp);
        }

        return dp[ind] = ans;
    }

    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return finder(0, s, dp);
    }
};
