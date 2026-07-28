class Solution {
private:
    int minCost(vector<int>& cost, int ind, vector<int>& dp) {
        if(ind == 0) return cost[0];
        if(ind == 1) return cost[1];
        if(dp[ind] != -1) return dp[ind];

        return dp[ind] = cost[ind] + min(minCost(cost, ind - 1, dp), minCost(cost, ind - 2, dp));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int idx = 2; idx < n; idx++) {
            dp[idx] = cost[idx] + min(dp[idx - 1], dp[idx - 2]); 
        }

        return min(dp[n - 1], dp[n - 2]);
    }
};
