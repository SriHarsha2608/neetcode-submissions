class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto it: flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<vector<int>> dp(n, vector<int>(k + 2, INT_MAX));
        dp[src][0] = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {src, 0}});

        while(!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second.first;
            int steps = pq.top().second.second;

            pq.pop();

            if(node == dst)
            {
                return dist;
            }

            if(dist > dp[node][steps])
            {
                continue;
            }

            if(steps > k)
            {
                continue;
            }

            for(auto it: adj[node])
            {
                if(dist + it.second < dp[it.first][steps + 1])
                {
                    dp[it.first][steps + 1] = dist + it.second;
                    pq.push({dp[it.first][steps + 1], {it.first, steps + 1}});
                }
            }
        }

        return -1;
    }
};
