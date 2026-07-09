class Solution {
public:
    int lastStoneWeightII(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int num: nums)
        {
            sum += num;
        }

        vector<bool> prev(sum + 1, false);

        prev[0] = true;

        if(nums[0] <= sum)
        {
            prev[nums[0]] = true;
        }

        for(int index = 1; index < n; index++)
        {
            vector<bool> cur(sum + 1, false);
            cur[0] = true;
            
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

        int mini = INT_MAX;
        for(int i = 0; i <= sum / 2; i++)
        {
            if(prev[i])
            {
                mini = min(mini, sum - 2*i);
            }
        }

        return mini;
    }
};