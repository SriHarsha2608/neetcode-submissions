class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0, el1 = 0;
        int count2 = 0, el2 = 0;

        for(int i = 0; i < n; i++)
        {
            if(count1 == 0 && nums[i] != el2)
            {
                el1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0 && nums[i] != el1)
            {
                el2 = nums[i];
                count2 = 1;
            }
            else if(nums[i] == el1)
            {
                count1++;
            }
            else if(nums[i] == el2)
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == el1)
            {
                count++;
            }
        } 
        if(count > n / 3)
        {
            ans.push_back(el1);
        }
        count = 0;
        if(el1 != el2)
        {
            for(int i = 0; i < n; i++)
            {
                if(nums[i] == el2)
                {
                    count++;
                }
            }
            if(count > n / 3)
            {
                ans.push_back(el2);
            }
        }
        return ans;
    }
};