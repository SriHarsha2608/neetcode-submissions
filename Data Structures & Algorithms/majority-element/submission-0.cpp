class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0, el = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if(count == 0)
            {
                el = nums[i];
            }
            if(el == nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }

        }
        return el;
    }
};