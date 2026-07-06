class Solution {
private:
    int LIS(vector<int>& nums, int prev, int index, vector<vector<int>> &dp)
    {
        if(index == nums.size())
        {
            return 0;
        }

        if(dp[index][prev + 1] != -1)
        {
            return dp[index][prev + 1];
        }

        int include = 0;
        if(prev == -1 || nums[index] > nums[prev])
        {
            include = 1 + LIS(nums, index, index + 1, dp);
        }

        int exclude = LIS(nums, prev, index + 1, dp);

        return dp[index][prev + 1] = max(include, exclude);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return LIS(nums, -1, 0, dp);
    }
};
