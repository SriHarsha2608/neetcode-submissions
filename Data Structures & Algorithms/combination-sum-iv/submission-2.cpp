class Solution {
    int combinationNum(vector<int> &nums, int target, vector<int>& dp)
    {
        if(target == 0)
        {
            return 1;
        }

        if(dp[target] != -1)
        {
            return dp[target];
        }


        int ans = 0; 
        for(int num: nums)
        {
            if(num <= target)
            {
                ans += combinationNum(nums, target - num, dp);
            }
        }

        return dp[target] = ans;
    }
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