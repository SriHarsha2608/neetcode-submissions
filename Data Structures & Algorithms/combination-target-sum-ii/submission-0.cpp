class Solution {
private:
    void findCombinationSum(vector<int>& candidates, int target, int ind, vector<vector<int>>& ans, vector<int>& ds) {
        if(target == 0) {
            ans.push_back(ds);
            return;
        }

        for(int i = ind; i < candidates.size(); i++) {
            if(i > ind && candidates[i] == candidates[i - 1]) continue;

            if(candidates[i] > target) break;

            ds.push_back(candidates[i]);
            findCombinationSum(candidates, target - candidates[i], i + 1, ans, ds);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;

        findCombinationSum(candidates, target, 0, ans, temp);

        return ans;
    }
};
