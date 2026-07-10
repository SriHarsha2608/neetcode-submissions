class Solution {
private:
    bool isMatching(string s, string p, int i, int j, vector<vector<int>>& dp)
    {
        if(i < 0 && j < 0)
        {
            return true;
        }
        if(j < 0)
        {
           return false; 
        }
        if(i < 0)
        {
            while(j >= 0)
            {
                if(p[j] == '*')
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

        if(s[i] == p[j])
        {
            return dp[i][j] = isMatching(s, p, i - 1, j - 1, dp);
        }
        else
        {
            if(p[j] == '.')
            {
                return dp[i][j] = isMatching(s, p, i - 1, j - 1, dp);
            }
            else if(p[j] == '*')
            {
                bool notTake = isMatching(s, p, i, j - 2, dp);

                bool take = false;
                if(p[j - 1] == '.' || p[j - 1] == s[i])
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
        vector<vector<int>> dp(n, vector<int>(m, - 1));
        return isMatching(s, p, n - 1, m - 1, dp);
    }
};
