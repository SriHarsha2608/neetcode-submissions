class Solution {
private:
    int dfs(vector<int>& piles, int l, int r, vector<vector<int>>& dp)
    {
        if(l > r)
        {
            return 0;
        }

        if(dp[l][r] != -1)
        {
            return dp[l][r];
        }

        int left = 0, right = 0;
        if((r - l) % 2 == 0)
        {
            left = piles[l];
            right = piles[r];
        }

        return dp[l][r] = max(left + dfs(piles, l + 1, r, dp), right + dfs(piles, l, r - 1, dp));
    }

public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int sum = 0;
        for(int num: piles)
        {
            sum += num;
        }
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int aliceScore = dfs(piles, 0, n - 1, dp);

        return aliceScore > sum - aliceScore;
    }
};