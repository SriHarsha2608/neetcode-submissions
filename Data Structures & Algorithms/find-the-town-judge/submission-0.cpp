class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n + 1, 0);

        vector<vector<int>> adj(n + 1);
        for(int i = 0; i < trust.size(); i++)
        {
            indegree[trust[i][1]]++;
            adj[trust[i][0]].push_back(trust[i][1]);
        }

        for(int i = 1; i <= n; i++)
        {
            if(indegree[i] == n - 1 && !adj[i].size())
            {
                return i;
            }
        }

        return -1;
    }
};