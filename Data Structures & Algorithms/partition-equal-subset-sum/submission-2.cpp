class Solution {
    bool sumPossible(vector<int> &nums, int sum)
    {
        int n = nums.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        for(int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }

        if(nums[0] <= sum)
        {
            dp[0][nums[0]] = true;
        }

        for(int index = 1; index < n; index++)
        {
            for(int j = 1; j <= sum; j++)
            {
                bool exclude = dp[index - 1][j];
                bool include = false;
                if(nums[index] <= j)
                {
                    include = dp[index - 1][j - nums[index]];
                }

                dp[index][j] = include | exclude;
            }
        }

        return dp[n - 1][sum];
    } 
    bool subsetSum(vector<int> &nums, int sum, int index, vector<vector<int>>& dp)
    {
        if(sum == 0)
        {
            return true;
        }

        if(index == 0)
        {
            return sum == nums[index];
        }
        if(dp[index][sum] != -1)
        {
            return dp[index][sum];
        }
        bool exclude = subsetSum(nums, sum, index - 1, dp);
        bool include = false;
        if(nums[index] <= sum)
        {
            include = subsetSum(nums, sum - nums[index], index - 1, dp);
        }

        return dp[index][sum] = include | exclude;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num: nums)
        {
            sum += num;
        }

        if(sum % 2 == 1)
        {
            return false;
        }
        // vector<vector<int>> dp(nums.size(), vector<int>(sum, -1));
        // return subsetSum(nums, sum / 2, nums.size() - 1, dp);
        return sumPossible(nums, sum / 2);
    }
};
