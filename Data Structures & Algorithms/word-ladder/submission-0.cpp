class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> st;
        for (string& word : wordList) {
            st.insert(word);
        }
        if (st.find(endWord) == st.end())
            return 0;

        int count = 1;

        unordered_map<string, int> mp;
        mp[beginWord] = 1;

        queue<string> q;
        q.push(beginWord);

        while (!q.empty()) {

            int n = q.size();

            for (int k = 0; k < n; k++) {

                string temp = q.front();
                q.pop();

                if (temp == endWord)
                    return count;

                for (int i = 0; i < temp.size(); i++) {

                    char original = temp[i];

                    for (int j = 0; j < 26; j++) {

                        temp[i] = 'a' + j;

                        if (mp.find(temp) == mp.end() &&
                            st.find(temp) != st.end()) {

                            q.push(temp);
                            mp[temp] = 1;
                        }
                    }

                    temp[i] = original;
                }
            }

            count++;
        }

        return 0;
    }
};