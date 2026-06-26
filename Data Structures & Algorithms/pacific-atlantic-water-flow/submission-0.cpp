class Solution {
private:
    void dfs(vector<vector<int>>& heights, int x, int y, vector<vector<bool>>& visited)
    {
        int n = heights.size(), m = heights[0].size();

        visited[x][y] = true;

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >=0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && heights[nx][ny] >= heights[x][y])
            {
                dfs(heights, nx, ny, visited);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();

        vector<vector<bool>> visitedPacific(n, vector<bool>(m, false));
        vector<vector<bool>> visitedAtlantic(n, vector<bool>(m, false));

        for(int i = 0; i < m; i++)
        {
            if(!visitedPacific[0][i])
            {
                dfs(heights, 0, i, visitedPacific);
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(!visitedPacific[i][0])
            {
                dfs(heights, i, 0, visitedPacific);
            }
        }

        for(int i = 0; i < m; i++)
        {
            if(!visitedAtlantic[n - 1][i])
            {
                dfs(heights, n - 1, i, visitedAtlantic);
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(!visitedAtlantic[i][m - 1])
            {
                dfs(heights, i, m - 1, visitedAtlantic);
            }
        }

        vector<vector<int>> ans;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(visitedPacific[i][j] && visitedAtlantic[i][j])
                {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
