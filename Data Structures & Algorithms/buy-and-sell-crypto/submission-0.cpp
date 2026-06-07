class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minimum = prices[0];

        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] < minimum)
            {
                minimum = prices[i];
            }

            ans = max(ans, prices[i] - minimum);
        }

        return ans;
    }
};
