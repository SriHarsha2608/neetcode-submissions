class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<int> prev(amount + 1, 0);
        prev[0] = 1;

        for(int i = 1; i <= amount; i++)
        {
            if(i % coins[0] == 0)
            {
                prev[i] = 1;
            }
        }

        for(int i = 1; i < n; i++)
        {
            prev[0] = 1;

            for(int j = 1; j <= amount; j++)
            {
                int exclude = prev[j];
                int include = 0;
                if(coins[i] <= j)
                {
                    include = prev[j - coins[i]];
                }

                prev[j] = exclude + include;
            }
        }

        return prev[amount];
    }
};
