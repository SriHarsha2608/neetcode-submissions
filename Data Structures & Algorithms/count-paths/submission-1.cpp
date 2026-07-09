class Solution {
private:
    int pathNum(int m, int n, vector<vector<int>>& dp)
    {
        if(m == 0 && n == 0)
        {
            return 1;
        }

        if(m < 0 || n < 0)
        {
            return 0;
        }
        
        if(dp[m][n] != -1)
        {
            return dp[m][n];
        }

        return dp[m][n] = pathNum(m - 1, n, dp) + pathNum(m, n - 1, dp);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return pathNum(m - 1, n - 1, dp);
    }
};
