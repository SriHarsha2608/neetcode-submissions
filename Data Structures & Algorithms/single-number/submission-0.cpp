class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor_value = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            xor_value = xor_value ^ nums[i];
        }
        return xor_value;
    }
};
