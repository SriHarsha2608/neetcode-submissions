class Solution {
    int lcs(string text1, string text2, int i, int j, vector<vector<int>>& dp)
    {
        if(i < 0 || j < 0)
        {
            return 0;
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if(text1[i] == text2[j])
        {
            return dp[i][j] = 1 + lcs(text1, text2, i - 1, j - 1, dp);
        }

        return dp[i][j] = max(lcs(text1, text2, i, j - 1, dp), lcs(text1, text2, i - 1, j, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(text1[i] == text2[j])
                {
                    dp[i][j] = 1;
                    if(i > 0 && j > 0)
                    {
                        dp[i][j] += dp[i - 1][j - 1];
                    }
                }
                else
                {
                    int left1 = 0;
                    if(i > 0)
                    {
                        left1 = dp[i - 1][j];
                    }

                    int left2 = 0;
                    if(j > 0)
                    {
                        left2 = dp[i][j - 1];
                    }

                    dp[i][j] = max(left1, left2);
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};
