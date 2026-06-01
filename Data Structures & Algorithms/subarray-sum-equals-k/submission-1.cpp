class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0, curSum = 0;
        map<int, int> mpp;
        mpp[0] = 1;

        for(int i = 0; i < n; i++)
        {
            curSum += nums[i];

            int diff = curSum - k;
            res+= mpp[diff];
            mpp[curSum]++;
        }

        return res;
    }
};