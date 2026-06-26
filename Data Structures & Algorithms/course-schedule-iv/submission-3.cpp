class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        vector<unordered_set<int>> preReq(numCourses);
        vector<int> indegree(numCourses, 0);

        for(int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto it: adj[node])
            {
                preReq[it].insert(node);
                preReq[it].insert(preReq[node].begin(), preReq[node].end());

                indegree[it]--;
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        

        vector<bool> ans;
        for(auto it: queries)
        {
            ans.push_back(preReq[it[1]].find(it[0]) != preReq[it[1]].end());
        }

        return ans;
    }
};