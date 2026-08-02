class Solution {
private:
    void combination(int n, int start, int k, vector<vector<int>>& ans, vector<int>& ds) {
        if(ds.size() == k) {
            ans.push_back(ds);
            return;
        }

        for(int i = start; i <= n; i++) {
            ds.push_back(i);
            combination(n, i + 1, k, ans, ds);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;

        combination(n, 1, k, ans, temp);

        return ans;
    }
};