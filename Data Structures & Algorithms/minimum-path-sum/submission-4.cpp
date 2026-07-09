class Solution {
private:
    int minPath(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp)
    {
        if(i == 0 && j == 0)
        {
            return grid[0][0];
        }

        if(i < 0 || j < 0)
        {
            return 1e9;
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        return dp[i][j] = grid[i][j] + min(minPath(grid, i - 1, j, dp), minPath(grid, i, j - 1, dp));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> prev(m, 0);

        prev[0] = grid[0][0];

        for(int i = 0; i < n; i++)
        {
            vector<int> cur(m, 0);
            for(int j = 0; j < m; j++)
            {
                if(i == 0 && j == 0)
                {
                    cur[j] = grid[0][0];
                    continue;
                }

                cur[j] = grid[i][j];

                int left = 1e9;
                if(i > 0)
                {
                    left = prev[j];
                }

                int up = 1e9;
                if(j > 0)
                {
                    up = cur[j - 1];
                }

                cur[j] += min(left, up);
            }

            prev = cur;
        }

        return prev[m - 1];
    }
};