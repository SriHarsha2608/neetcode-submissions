class Solution {
    bool sumPossible(vector<int> &nums, int sum)
    {
        int n = nums.size();
        vector<bool> prev(sum + 1, false), cur(sum + 1, false);

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
        
        return sumPossible(nums, sum / 2);
    }
};
