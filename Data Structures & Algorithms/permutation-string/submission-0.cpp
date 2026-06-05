class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if (n > m) {
            return false;
        }

        map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s1[i]]++;
        }

        map<char, int> mp1;
        for (int i = 0; i < n; i++) {
            mp1[s2[i]]++;
        }

        int i = 0;
        int j = n;

        while (j < m) {
            if (mp1 == mp) {
                return true;
            }

            mp1[s2[i]]--;
            if (mp1[s2[i]] == 0) {
                mp1.erase(s2[i]);
            }

            i++;

            mp1[s2[j]]++;
            j++;
        }

        return mp1 == mp;
    }
};
