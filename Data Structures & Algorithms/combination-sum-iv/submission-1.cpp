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
        vector<int> dp(target + 1, -1);
        return combinationNum(nums, target, dp);
    }
};