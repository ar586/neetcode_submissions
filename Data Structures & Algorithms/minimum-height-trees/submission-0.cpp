class Solution {
   public:
    int bfs(vector<vector<int>>& adj, int start) {
        int n = adj.size();
        vector<int> vis(n, 0);
        queue<int> q;

        q.push(start);
        vis[start] = 1;

        int level = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                int node = q.front();
                q.pop();

                for (auto nei : adj[node]) {
                    if (!vis[nei]) {
                        vis[nei] = 1;
                        q.push(nei);
                    }
                }
            }

            level++;
        }

        return level;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        map<int,vector<int>> checker;
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for (int i = 0; i < n; i++) {
            int height = bfs(adj,i);
            checker[height].push_back(i);
        }
        return checker.begin()->second;
    }
};