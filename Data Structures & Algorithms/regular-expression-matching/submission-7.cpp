class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();

        vector<bool> prev(m + 1, false);
        prev[0] = true;

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
                prev[jj] = true;
            }
        }

        for(int i = 1; i <= n; i++)
        {
            vector<bool> cur(m + 1, false);

            for(int j = 1; j <= m; j++)
            {
                if(s[i - 1] == p[j - 1])
                {
                    cur[j] = prev[j - 1];
                }
                else
                {
                    if(p[j - 1] == '.')
                    {
                        cur[j] = prev[j - 1];
                    }
                    else if(p[j - 1] == '*')
                    {
                        bool notTake = cur[j - 2];

                        bool take = false;
                        if(p[j - 2] == '.' || p[j - 2] == s[i - 1])
                        {
                            take = prev[j];
                        }

                        cur[j] = take || notTake;
                    }
                }
            }

            prev = cur;
        }
        return prev[m];
    }
};
