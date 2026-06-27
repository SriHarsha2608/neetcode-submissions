class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        dp[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        while(!pq.empty())
        {
            int height = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;

            pq.pop();

            if(height > dp[x][y])
            {
                continue;
            }
 
            if(x == n - 1 && y == n - 1)
            {
                return height;
            }

            

            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < n)
                {
                    int maxHeight = max(height, grid[nx][ny]);
                    if(maxHeight < dp[nx][ny])
                    {
                        dp[nx][ny] = maxHeight;
                        pq.push({dp[nx][ny], {nx, ny}});
                    }
                }
            }
        }
    }
};
