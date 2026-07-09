class Solution {
private:
    int f(int amount, vector<int>& coins, int index, vector<vector<int>>& dp)
    {
        if(amount == 0)
        {
            return 1;
        }
        
        if(index == 0)
        {
            if(amount % coins[0] == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        if(dp[index][amount] != -1)
        {
            return dp[index][amount];
        }

        int exclude = f(amount, coins, index - 1, dp);
        int include = 0;
        if(coins[index] <= amount)
        {
            include = f(amount - coins[index], coins, index, dp);
        }

        return dp[index][amount] = exclude + include;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return f(amount, coins, coins.size() - 1, dp);
    }
};
