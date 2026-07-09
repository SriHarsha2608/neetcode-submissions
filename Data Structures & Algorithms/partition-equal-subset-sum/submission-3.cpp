class Solution {
    bool sumPossible(vector<int> &nums, int sum)
    {
        int n = nums.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        vector<bool> prev(sum + 1, false), cur(sum + 1, false);

        for(int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        prev[0] = true;
        if(nums[0] <= sum)
        {
            prev[nums[0]] = true;
        }

        for(int index = 1; index < n; index++)
        {
            for(int j = 1; j <= sum; j++)
            {
                bool exclude = prev[j];
                bool include = false;
                if(nums[index] <= j)
                {
                    include = prev[j - nums[index]];
                }

                cur[j] = include | exclude;
            }

            prev = cur;
        }

        return prev[sum];
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
