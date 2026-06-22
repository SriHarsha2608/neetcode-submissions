class Solution {
public:
    int helper(string &s, int i, vector<int> &dp)
    {
        if(i < 0)
        {
            return 1;
        }

        if(dp[i] != -1)
        {
            return dp[i];
        }

        if(s[i] == '0')
        {
            if(i == 0)
            {
                return 0;
            }
            if(s[i - 1] == '1' || s[i - 1] == '2')
            {
                return dp[i] = helper(s, i - 2, dp);
            }

            return dp[i] = 0;
        }

        int ans = helper(s, i - 1, dp);
        if(i > 0 && (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7')))
        {
            ans += helper(s, i - 2, dp);
        }
        return dp[i] = ans;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return helper(s, s.size() - 1, dp);
    }
};
