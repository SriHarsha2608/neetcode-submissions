class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int bits = 32;
        uint32_t ans = 0; 
        for(int i = 0; i < 32; i++)
        {
            int num = n;
            ans += ((num >> i) & 1) * (1 << (31 - i));
        }

        return ans;
    }
};
