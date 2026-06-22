class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int minimum = 1, maximum = 1;

        for(int num: nums)
        {
            int product = maximum * num;

            maximum = max(max(maximum * num, minimum * num), num);
            minimum = min(min(product, minimum * num), num);

            ans = max(maximum, ans);
        }

        return ans;
    }
};
