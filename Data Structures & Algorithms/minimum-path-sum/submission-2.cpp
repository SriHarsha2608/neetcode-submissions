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
        vector<vector<int>> dp(n, vector<int> (m, 0));

        dp[0][0] = grid[0][0];

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == 0 && j == 0)
                {
                    continue;
                }

                dp[i][j] = grid[i][j];

                int left = 1e9;
                if(i > 0)
                {
                    left = dp[i - 1][j];
                }

                int up = 1e9;
                if(j > 0)
                {
                    up = dp[i][j - 1];
                }

                dp[i][j] += min(left, up);
            }
        }
        return dp[n - 1][m - 1];
    }
};