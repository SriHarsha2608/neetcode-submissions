class DisjointSet {
private:
    vector<int> size, parent;

public:
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if(parent[node] == node) {
            return node;
        }

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u), ulp_v = findUPar(v);

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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n + 1);

        unordered_map<string, int> mpp;

        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                if(mpp.find(accounts[i][j]) == mpp.end()) {
                    mpp[accounts[i][j]] = i;
                } else {
                    ds.unionBySize(i, mpp[accounts[i][j]]);
                }
            }
        }

        vector<string> mergedMail[n];
        for(auto it: mpp) {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i = 0; i < n; i++) {
            if(mergedMail[i].empty()) continue;

            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for(int j = 0; j < mergedMail[i].size(); j++) {
                temp.push_back(mergedMail[i][j]);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};