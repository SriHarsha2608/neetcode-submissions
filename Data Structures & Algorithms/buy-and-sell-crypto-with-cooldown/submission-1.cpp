class Solution {
// private:
//     int f(vector<int>& prices, int buy, int index, vector<vector<int>>& dp)
//     {
//         if(index >= prices.size())
//         {
//             return 0;
//         }

//         if(dp[index][buy] != -1)
//         {
//             return dp[index][buy];
//         }

//         if(buy == 1)
//         {
//             int buyNow = -prices[index] + f(prices, 0, index + 1, dp);
//             int notBuy = f(prices, 1, index + 1, dp);

//             return dp[index][buy] =  max(buyNow, notBuy);
//         }
//         else if(buy == 0)
//         {
//             int sellNow = prices[index] + f(prices, 1, index + 2, dp);
//             int notSell = f(prices, 0, index + 1, dp);

//             return dp[index][buy] = max(sellNow, notSell);
//         }
//     }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for(int i = n - 1; i >= 0; i--)
        {
            dp[i][1] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
            
            dp[i][0] = max(prices[i] + dp[i + 2][1], dp[i + 1][0]);
        }

        return dp[0][1];
    }
};
