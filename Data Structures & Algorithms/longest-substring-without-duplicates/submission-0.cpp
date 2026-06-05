class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<int> st;

        int i = 0;
        int j = 0;

        int maxi = 0;

        while (j < s.size()) {

            while (st.find(s[j]) != st.end()) {
                st.erase(s[i]);
                i++;
            }

            st.insert(s[j]);

            maxi = max(maxi, j - i + 1);

            j++;
        }

        return maxi;
    }
};