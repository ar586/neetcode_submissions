class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);

        int l = 0;
        int r = 0;

        int maxFreq = 0;
        int maxi = 0;

        while (r < s.size()) {

            freq[s[r] - 'A']++;

            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            while ((r - l + 1) - maxFreq > k) {
                freq[s[l] - 'A']--;
                l++;
            }

            maxi = max(maxi, r - l + 1);

            r++;
        }

        return maxi;
    }
};
