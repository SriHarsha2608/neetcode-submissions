class Solution {
public:
    int robHouse(vector<int>& nums, int l, int r) {
        int n = nums.size();
        if(n == 1) return nums[0];

        int a = 0;
        int b = 0;

        for(int i = l; i <= r; i++)
        {
            int include = nums[i] + a;
            int exclude = b;
            
            a = b;   
            b = max(include, exclude);
        }

        return b;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(robHouse(nums, 0, n - 2), robHouse(nums, 1, n - 1));
    }
};
