class Solution {
   public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int curr = 0;
        for (auto& trip : trips) {
            int passengers = trip[0];
            int start = trip[1];
            int end = trip[2];
            while (!pq.empty() && pq.top().first <= start) {
                curr -= pq.top().second;
                pq.pop();
            }
            curr += passengers;
            if (curr > capacity) return false;
            pq.push({end, passengers});
        }
        return true;
    }
};