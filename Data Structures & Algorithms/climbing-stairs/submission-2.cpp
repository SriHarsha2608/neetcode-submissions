class Solution {
public:
    int helper(vector<int>&dp, int n)
    {
        if(n <= 1)
        {
            return 1; 
        }
        if(dp[n] != -1)
        {
            return dp[n];
        }

        return dp[n] = helper(dp, n - 1) + helper(dp, n - 2);
    }
    int climbStairs(int n) {
        int a = 1, b = 1;
        int c = 1;
        for(int i = 1; i < n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }

        return c;
    }
};
