class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &f : flights)
            adj[f[0]].push_back({f[1], f[2]});

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        vector<int> stops(n, INT_MAX);

        pq.push({0, {0, src}});

        while (!pq.empty()) {
            int cost = pq.top().first;
            int stop = pq.top().second.first;
            int node = pq.top().second.second;
            pq.pop();

            if (node == dst) return cost;

            if (stop > k || stop > stops[node])
                continue;

            stops[node] = stop;

            for (auto &it : adj[node]) {
                pq.push({cost + it.second,
                         {stop + 1, it.first}});
            }
        }

        return -1;
    }
};
