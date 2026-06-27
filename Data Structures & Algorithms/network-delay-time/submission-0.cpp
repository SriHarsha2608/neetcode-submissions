class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto time: times)
        {
            adj[time[0]].push_back({time[1], time[2]});
        }

        vector<int> distance(n + 1, INT_MAX);
        distance[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while(!pq.empty())
        {
            int node = pq.top().second;
            int dist = pq.top().first;

            pq.pop();

            for(auto it: adj[node])
            {
                if(dist + it.second < distance[it.first])
                {
                    distance[it.first] = dist + it.second;
                    pq.push({distance[it.first], it.first});
                }
            }
        }

        auto it = *max_element(distance.begin() + 1, distance.end());
        
        if(it == INT_MAX)
        {
            return -1;
        }

        return it;
    }
};
