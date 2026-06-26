class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 0}});
        dp[0][0] = 0;

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        while(!pq.empty())
        {
            int effort = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;

            pq.pop();

            if(effort > dp[x][y])
            {
                continue;
            }

            if(x == n - 1 && y == m - 1)
            {
                return effort;
            }

            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < n && ny >=0 & ny < m)
                {
                    int newEffort = max(effort, abs(heights[nx][ny] - heights[x][y]));
                    if(newEffort < dp[nx][ny])
                    {
                        dp[nx][ny] = newEffort;
                        pq.push({newEffort, {nx, ny}});
                    }
                }
            }
            
        }    
        return 0;
        
    }
};