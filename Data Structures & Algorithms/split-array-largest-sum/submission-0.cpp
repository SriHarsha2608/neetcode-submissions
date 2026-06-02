class Solution {
public:
    bool canSplit(vector<int> &nums, int k, int maxSum)
    {
        int count = 1;
        int sum = 0;
        for(int num : nums)
        {
            if(sum + num > maxSum)
            {
                count++;
                sum = num;
            }
            else
            {
                sum += num;
            }
        }

        return count <= k;
    }


    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end()), high = accumulate(nums.begin(), nums.end(), 0);
        int ans = low;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(canSplit(nums, k, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};