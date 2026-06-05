class Solution {
   public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        priority_queue<pair<int, char>> pq;
        for (auto& p : freq) pq.push({p.second, p.first});
        string ans;
        while (pq.size() >= 2) {
            auto [cnt1, ch1] = pq.top();
            pq.pop();
            auto [cnt2, ch2] = pq.top();
            pq.pop();
            ans += ch1;
            ans += ch2;
            cnt1--;
            cnt2--;
            if (cnt1 > 0) pq.push({cnt1, ch1});
            if (cnt2 > 0) pq.push({cnt2, ch2});
        }
        if (!pq.empty()) {
            auto [cnt, ch] = pq.top();
            if (cnt > 1) return "";
            ans += ch;
        }
        return ans;
    }
};