class Solution {
private:
    int countWays(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& dp)
    {
        if(i < 0 || j < 0)
        {
            return 0;
        }
        
        if(obstacleGrid[i][j] == 1)
        {
            return 0;
        }

        if(i == 0 && j == 0)
        {
            return 1;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        return dp[i][j] = countWays(obstacleGrid, i - 1, j, dp) + countWays(obstacleGrid, i, j - 1, dp);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        if(obstacleGrid[0][0] != 1)
        {
            dp[0][0] = 1;
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == 0 && j == 0)
                {
                    continue;
                }

                if(obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                    continue;
                }

                if(i > 0)
                {
                    dp[i][j] += dp[i - 1][j];
                }
                
                if(j > 0)
                {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};