class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<int> next(m + 1, 0);
        next[m] = 1;
        // for(int i = 0; i <= n; i++)
        // {
        //     next[m] = 1;
        // }

        for(int i = n - 1; i >= 0; i--)
        {
            vector<int> cur(m + 1, 0);
            cur[m] = 1;

            for(int j = m - 1; j >= 0; j--)
            {
                if(s[i] == t[j])
                {
                    cur[j] =  next[j + 1] + next[j]; 
                }
                else
                {
                    cur[j] = next[j];
                }
            }
            next = cur;
        }
        return next[0];
    }
};
