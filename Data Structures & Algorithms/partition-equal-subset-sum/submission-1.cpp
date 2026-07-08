class Solution { 
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
        vector<vector<int>> dp(nums.size(), vector<int>(sum, -1));
        return subsetSum(nums, sum / 2, nums.size() - 1, dp);
    }
};
