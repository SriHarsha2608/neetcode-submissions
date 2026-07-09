class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<int> prev(amount + 1, 0), cur(amount + 1, 0);
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
            vector<int> cur(amount + 1, 0);
            cur[0] = 1;

            for(int j = 1; j <= amount; j++)
            {
                int exclude = prev[j];
                int include = 0;
                if(coins[i] <= j)
                {
                    include = cur[j - coins[i]];
                }

                cur[j] = exclude + include;
            }
            
            prev = cur;
        }

        return prev[amount];
    }
};
