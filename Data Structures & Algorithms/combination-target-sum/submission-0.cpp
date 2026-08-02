class Solution {
private:
    void f(vector<int> &nums, int target, int ind, vector<vector<int>>& ans, vector<int> &ds) {
        if(ind == nums.size()) {
            if(target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        if(target >= nums[ind]) {
            ds.push_back(nums[ind]);
            f(nums, target - nums[ind], ind, ans, ds);
            ds.pop_back(); 
        }

        f(nums, target, ind + 1, ans, ds);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        f(nums, target, 0, ans, temp);

        return ans;
    }
};
