class Solution {
private:
    int num(string s, string t, int i, int j, vector<vector<int>>& dp)
    {
        if(j == t.size())
        {
            return 1;
        }

        if(i == s.size())
        {
            return 0;
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if(s[i] == t[j])
        {
            return dp[i][j] = num(s, t, i + 1, j + 1, dp) + num(s, t, i + 1, j, dp); 
        }
        else
        {
            return dp[i][j] = num(s, t, i + 1, j, dp);
        }
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = 0; i <= n; i++)
        {
            dp[i][m] = 1;
        }

        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                if(s[i] == t[j])
                {
                    dp[i][j] =  dp[i + 1][j + 1] + dp[i + 1][j]; 
                }
                else
                {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
        return dp[0][0];
    }
};
