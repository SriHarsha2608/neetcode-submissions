class Solution {
private:
    void dfs(vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& visited)
    {
        visited[x][y] = true;
        int n = grid.size(), m = grid[0].size();

        int dx[] = {0 , 0, 1, -1};
        int dy[] = {1 , -1, 0 , 0};

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] == '1')
            {
                dfs(grid, nx, ny, visited);
            }
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!visited[i][j] && grid[i][j] == '1')
                {
                    dfs(grid, i, j, visited);
                    count++;
                }
            }
        }

        return count;
    }
};
