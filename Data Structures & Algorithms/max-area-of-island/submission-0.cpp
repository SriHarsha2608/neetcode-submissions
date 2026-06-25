class Solution {
private:
    int dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited)
    {
        int n = grid.size(), m = grid[0].size();
        if(x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 0)
        {
            return 0;
        }
        int ans = 1;
        visited[x][y] = true;

        int dx[] = {0 , 0, 1, -1};
        int dy[] = {1 , -1, 0 , 0};

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(!(nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] == 0) && !visited[nx][ny])
            {
                ans += dfs(grid, nx, ny, visited);
            }
        }
        return ans;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m ; j++)
            {
                if(grid[i][j] == 1 && !visited[i][j])
                {
                    ans = max(ans, dfs(grid, i, j, visited));
                }
            }
        }

        return ans;
    }
};
