class Solution {
private:
    bool isMatching(string s, string p, int i, int j, vector<vector<int>>& dp)
    {
        if(i == 0 && j == 0)
        {
            return true;
        }
        if(j == 0)
        {
           return false; 
        }
        if(i == 0)
        {
            while(j >= 1)
            {
                if(p[j - 1] == '*')
                {
                    j -= 2;
                }
                else
                {
                    return false;
                }
            }

            return true;
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if(s[i - 1] == p[j - 1])
        {
            return dp[i][j] = isMatching(s, p, i - 1, j - 1, dp);
        }
        else
        {
            if(p[j - 1] == '.')
            {
                return dp[i][j] = isMatching(s, p, i - 1, j - 1, dp);
            }
            else if(p[j - 1] == '*')
            {
                bool notTake = isMatching(s, p, i, j - 2, dp);

                bool take = false;
                if(p[j - 2] == '.' || p[j - 2] == s[i - 1])
                {
                    take = isMatching(s, p, i - 1, j, dp);
                }

                return dp[i][j] = take || notTake;
            }
            else
            {
                return dp[i][j] = false;
            }
        }

    }
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        // for(int i = 1; i <= n; i++)
        // {
        //     dp[i][0] = false;
        // }

        for(int jj = 1; jj <= m; jj++)
        {
            int j = jj;
            bool possible = true;

            while(j >= 1)
            {
                if(p[j - 1] == '*')
                {
                    j -= 2;
                }
                else
                {
                    possible = false;
                    break;
                }
            }

            if(possible)
            {
                dp[0][jj] = true;
            }
        }

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s[i - 1] == p[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    if(p[j - 1] == '.')
                    {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    else if(p[j - 1] == '*')
                    {
                        bool notTake = dp[i][j - 2];

                        bool take = false;
                        if(p[j - 2] == '.' || p[j - 2] == s[i - 1])
                        {
                            take = dp[i - 1][j];
                        }

                        dp[i][j] = take || notTake;
                    }
                    // else
                    // {
                    //     dp[i][j] = false;
                    // }
                }
            }
        }
        return dp[n][m];
    }
};
