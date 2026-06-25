class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m , false));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 0)
                {
                    q.push({i, j});
                }
            }
        }

        int distance = 0;
        while(!q.empty())
        {
            int len = q.size();
            for(int i = 0; i < len; i++)
            {
                int x = q.front().first;
                int y = q.front().second;

                q.pop();
                visited[x][y] = true;
                grid[x][y] = min(distance, grid[x][y]);

                int dx[] = {0, 0, 1, -1};
                int dy[] = {1, -1, 0, 0};

                for(int j = 0; j < 4; j++)
                {
                    int nx = x + dx[j];
                    int ny = y + dy[j];

                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] != -1)
                    {
                        q.push({nx, ny});
                    }
                }
            }
            distance++;
            
        }

    }
};
