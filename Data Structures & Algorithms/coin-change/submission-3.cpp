class Solution {
public:
    int helper(vector<int>& coins, int amount, vector<int> &dp)
    {
        if(amount == 0)
        {
            return 0;
        }

        if(dp[amount] != -1)
        {
            return dp[amount];
        }

        int ans = 1e9;

        for(int i = 0; i < coins.size(); i++)
        {   
            if(amount >= coins[i])
            {            
                ans = min(ans, 1 + helper(coins, amount - coins[i], dp));
            }   
        }

        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, 1e9);
        
        dp[0] = 0;

        for(int coin = 0; coin <= amount; coin++)
        {
            for(int i = 0; i < coins.size(); i++)
            {   
                if(coin >= coins[i])
                {            
                    dp[coin] = min(dp[coin], 1 + dp[coin - coins[i]]);
                }   
            }
        }
        
        if(dp[amount] == 1e9)
        {
            return -1;
        }
        else
        {
            return dp[amount];
        }
    }
};
