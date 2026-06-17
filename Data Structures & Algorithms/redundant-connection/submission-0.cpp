class Solution {
public:
    class DSU {
    private:
        std::vector<int> parent;
        std::vector<int> size;
        int num_components;

    public:
        DSU(int n) {
            parent.resize(n);
            std::iota(parent.begin(), parent.end(), 0); 
            size.assign(n, 1);
            num_components = n;
        }

        int find(int i) {
            if (parent[i] == i) {
                return i;
            }
            return parent[i] = find(parent[i]); 
        }

        bool unite(int i, int j) {
            int root_i = find(i);
            int root_j = find(j);

            if (root_i == root_j) {
                return false; 
            }

            if (size[root_i] < size[root_j]) {
                parent[root_i] = root_j;
                size[root_j] += size[root_i];
            } else {
                parent[root_j] = root_i;
                size[root_i] += size[root_j];
            }
            
            num_components--; 
            return true;
        }

        int get_size(int i) {
            return size[find(i)];
        }

        int get_components() {
            return num_components;
        }
    };

    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n + 1); 

        for (int i = 0; i < n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (dsu.find(u) == dsu.find(v)) {
                return edges[i];
            } else {
                dsu.unite(u, v);
            }
        }
        return {};
    }
};
