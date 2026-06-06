class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]] = i;
        }
        int i = 0;
        int j = mp[s[0]];
        int si = 0;
        vector<int> ans;
        while (j < s.size()) {
            while (i <= j) {
                j = max(j, mp[s[i]]);
                i++;
            }
            ans.push_back(j - si + 1);
            si = j + 1;
            i = j + 1;
            if (i == s.size()) break;
            j = mp[s[i]];
        }
        return ans;
    }
};
