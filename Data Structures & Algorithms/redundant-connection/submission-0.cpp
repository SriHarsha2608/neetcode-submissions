class DisjointSet {
private:
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if(node == parent[node]) {
            return node;
        }

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int count = 0, n = edges.size();
        DisjointSet ds(n + 1);

        for(auto edge: edges) {
            int u = edge[0], v = edge[1];

            if(ds.findUPar(u) == ds.findUPar(v)) {
                return {u, v};
            } else {
                ds.unionBySize(u, v);
            }
        }


    }
};
