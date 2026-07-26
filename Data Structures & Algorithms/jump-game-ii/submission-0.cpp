class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int l = 0, r = 0;
        while(r < n - 1) {
            int maxi = 0;
            while(l <= r) {
                maxi = max(maxi, l + nums[l]);
                l++;
            }
            l = r + 1;
            r = maxi;
            jumps++;
        }

        return jumps;
    }
};
