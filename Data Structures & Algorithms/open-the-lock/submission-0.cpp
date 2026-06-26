class Solution {
private:
    vector<string> children(string str)
    {
        vector<string> ans;
        for(int i = 0; i < 4; i++)
        {
            string next = str;
            next[i] = (next[i] - '0' + 1) % 10 + '0';
            ans.push_back(next);

            next = str;
            next[i] = (next[i] - '0' -1 + 10) % 10 + '0';
            ans.push_back(next);
        }

        return ans;
    }

public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(deadends.begin(), deadends.end());

        if(st.find("0000") != st.end())
        {
            return -1;
        }

        queue<pair<string, int>> q;
        q.push({"0000", 0});
        
        while(!q.empty())
        {
            string node = q.front().first;
            int steps = q.front().second;

            q.pop();

            if(node == target)
            {
                return steps;
            }

            for(auto it: children(node))
            {
                if(st.find(it) == st.end())
                {
                    st.insert(it);
                    q.push({it, steps + 1});
                }
            }
        }

        return -1;
    }
};