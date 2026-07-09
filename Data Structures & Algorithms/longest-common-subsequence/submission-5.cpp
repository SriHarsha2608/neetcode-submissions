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
        vector<int>prev(m, 0), cur(m, 0);

        for(int i = 0; i < n; i++)
        {
            // vector<int> cur(m , 0);
            for(int j = 0; j < m; j++)
            {
                if(text1[i] == text2[j])
                {
                    cur[j] = 1;
                    if(i > 0 && j > 0)
                    {
                        cur[j] += prev[j - 1];
                    }
                }
                else
                {
                    int left1 = 0;
                    if(i > 0)
                    {
                        left1 = prev[j];
                    }

                    int left2 = 0;
                    if(j > 0)
                    {
                        left2 = cur[j - 1];
                    }

                    cur[j] = max(left1, left2);
                }
            }
            prev = cur;
        }
        return prev[m - 1];
    }
};
