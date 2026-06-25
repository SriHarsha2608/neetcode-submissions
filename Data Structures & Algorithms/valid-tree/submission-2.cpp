class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // if(edges.size() != n - 1)
        // {
        //     return false;
        // }

        vector<vector<int>> adj(n);

        for(int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        queue<pair<int, int>> q;
        vector<bool> visited(n, false);

        q.push({0, -1});
        visited[0] = true;

        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;

            q.pop();

            for(auto it: adj[node])
            {
                if(!visited[it])
                {
                    q.push({it, node});
                    visited[it] = true;
                }
                else if(it != parent)
                {
                    return false;
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                return false;
            }
        }

        return true;
    }
};
