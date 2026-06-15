class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        // vector<int> dp(n, 0);
        int a = nums[0];
        int b = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++)
        {
            int include = nums[i] + a;
            int exclude = b;
            
            a = b;   
            b = max(include, exclude);
        }

        return b;
    }
};
