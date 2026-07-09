class Solution {
private:
    int numWays(vector<int> &nums, int target, int index)
    {
        if(index == 0)
        {
            if(target == 0 && nums[0] == 0)
            {
                return 2;
            }
            if(target == 0 || nums[0] == target)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        int exclude = numWays(nums, target, index - 1);
        int include = 0;
        if(nums[index] <= target)
        {
            include = numWays(nums, target - nums[index], index - 1);
        }

        return include + exclude;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int num: nums)
        {
            sum += num;
        }

        if(sum < abs(target))
        {
            return 0;
        }

        if((sum - target) % 2 != 0)
        {
            return 0;
        }

        int reqSum = (sum - target) / 2;

        return numWays(nums, reqSum, nums.size() - 1);
    }
};
