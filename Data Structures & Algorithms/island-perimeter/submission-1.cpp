class Solution {
private:
    int perimeter = 0;

    void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>> &visited)
    {
        visited[x][y] = true;

        int n = grid.size();
        int m = grid[0].size();

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == 0)
            {
                perimeter++;
            }
            else
            {
                if(!visited[nx][ny])
                {
                    dfs(grid, nx, ny, visited);
                }
            }
        }
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1 && !visited[i][j])
                {
                    dfs(grid, i, j, visited);
                }
            }
        }

        return perimeter;
    }
};