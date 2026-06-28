class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto it: flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dp(n, INT_MAX);
        dp[src] = 0;

        queue<pair<int, pair<int, int>>> q;        
        q.push({0, {src, 0}});

        while(!q.empty())
        {
            int steps = q.front().first;
            int node = q.front().second.first;
            int dist = q.front().second.second;

            q.pop();

            // if(dist > dp[node])
            // {
            //     continue;
            // }

            if(steps > k)
            {
                continue;
            }

            for(auto it: adj[node])
            {
                if(dist + it.second < dp[it.first])
                {
                    dp[it.first] = dist + it.second;
                    q.push({steps + 1, {it.first, dp[it.first]}});
                }
            }
        }

        return dp[dst] == INT_MAX ? -1 : dp[dst];
    }
};
