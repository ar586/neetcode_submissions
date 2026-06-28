class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> rank;
        for (int i = 0; i < order.size(); i++) {
            rank[order[i]] = i;
        }
        for (int i = 0; i < words.size() - 1; i++) {
            string &a = words[i];
            string &b = words[i + 1];

            int j = 0;
            while (j < a.size() && j < b.size()) {
                if (a[j] != b[j]) {
                    if (rank[a[j]] > rank[b[j]])
                        return false;
                    break;
                }
                j++;
            }
            if (j == b.size() && a.size() > b.size())
                return false;
        }

        return true;
    }
};