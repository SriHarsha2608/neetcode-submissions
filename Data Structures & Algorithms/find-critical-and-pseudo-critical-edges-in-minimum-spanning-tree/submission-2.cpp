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

    int findUParent(int node) {
        if(parent[node] == node) {
            return node;
        }

        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUParent(u), ulp_v = findUParent(v);
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
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<array<int, 4>> edgeList;
        for(int i = 0; i < edges.size(); i++) {
            edgeList.push_back({edges[i][0], edges[i][1], edges[i][2], i});
        }

        sort(edgeList.begin(), edgeList.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });

        int mstWeight = 0;
        DisjointSet ds(n);
        for(auto& edge: edgeList) {
            if(ds.findUParent(edge[0]) != ds.findUParent(edge[1])) {
                mstWeight += edge[2];
                ds.unionBySize(edge[0], edge[1]);
            }
        }

        vector<int> critical, pseudo;
        for(auto& edge: edgeList) {
            DisjointSet ds1(n);
            int weight = 0;
            int cnt = 0;

            for(auto& other: edgeList) {
                if(other[3] != edge[3] && ds1.findUParent(other[0]) != ds1.findUParent(other[1])) {
                    weight += other[2];
                    ds1.unionBySize(other[0], other[1]);
                    cnt++;
                }
            }

            if(cnt != n - 1 || weight > mstWeight) {
                critical.push_back(edge[3]);
                continue;
            }

            DisjointSet ds2(n);
            weight = edge[2];
            cnt = 1;

            ds2.unionBySize(edge[0], edge[1]);

            for(auto& other: edgeList) {
                if(other[3] != edge[3] && ds2.findUParent(other[0]) != ds2.findUParent(other[1])) {
                    weight += other[2];
                    ds2.unionBySize(other[0], other[1]);
                    cnt++;
                }
            }

            if(cnt == n - 1 && weight == mstWeight) {
                pseudo.push_back(edge[3]);
            }
        }

        return {critical, pseudo};
    }
};