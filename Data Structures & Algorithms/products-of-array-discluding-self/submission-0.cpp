class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftProduct(n+1, 1), rightProduct(n+1, 1);
        for(int i = 0;i < n; i++)
        {
            leftProduct[i+1] = leftProduct[i] * nums[i];
        }
        for(int i = n - 1;i >= 0; i--)
        {
            rightProduct[i] = rightProduct[i+1] * nums[i];
        }

        vector<int> ans;
        for(int i = 0;i < n; i++)
        {
            ans.push_back(leftProduct[i]*rightProduct[i+1]);
        }
        return ans;
    }
};
