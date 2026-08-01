class Solution {
private:

public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < (1 << n); i++) {
            int curXor = 0;
            for(int j = 0; j < n; j++) {
                if(((i >> j) & 1) != 0) {
                    curXor ^= nums[j];
                } 
            }
            sum += curXor;
        }

        return sum;
    }
};