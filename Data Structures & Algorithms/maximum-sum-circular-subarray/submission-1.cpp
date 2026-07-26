class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int globMax = nums[0], globMin = nums[0];
        int curMin = 0, curMax = 0, total = 0;

        for(int i = 0; i < nums.size(); i++) {
            curMax = max(curMax + nums[i], nums[i]);
            globMax = max(globMax, curMax);

            curMin = min(curMin + nums[i], nums[i]);
            globMin = min(globMin, curMin);

            total += nums[i];
        }

        if(globMax > 0) {
            return max(globMax, total - globMin);
        }
        return globMax;
    }
};