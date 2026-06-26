class Solution {
private:
    void dfs(vector<vector<int>>& adj, int node, vector<bool>& visited)
    {
        visited[node] = true;

        for(auto it: adj[node])
        {
            if(!visited[it])
            {
                dfs(adj, it, visited);
            }
        }

    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> visited(n, false);
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                dfs(adj, i, visited);
                count++;
            }
        }

        return count;
    }
};
