class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);

        dp[0] = 1;

        for(int i = 1; i <= target; i++)
        {
            int ans = 0; 
            for(int num: nums)
            {
                if(num <= i)
                {
                    ans += dp[i - num];
                }
            }

            dp[i] = ans;
        }
        return dp[target];
    }
};