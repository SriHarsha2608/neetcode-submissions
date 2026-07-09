class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        vector<int> cur(2, 0), next1(2, 0), next2(2, 0);

        for(int i = n - 1; i >= 0; i--)
        {
            cur[1] = max(-prices[i] + next1[0], next1[1]);
            
            cur[0] = max(prices[i] + next2[1], next1[0]);

            next2 = next1;
            next1 = cur;
        }

        return cur[1];
    }
};
