class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor_val = 0;
        for(int i = 0 ; i <= n; i++)
        {
            xor_val ^= i;
        }

        int arr_xor = 0;
        for(int i = 0; i < n; i++)
        {
            arr_xor ^= nums[i];
        }

        return xor_val ^ arr_xor;
    }
};
