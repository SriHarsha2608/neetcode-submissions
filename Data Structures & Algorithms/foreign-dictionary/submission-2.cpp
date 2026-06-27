class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;

        for(auto it: words)
        {
            for(char ch: it)
            {
                indegree[ch] = 0;
            }
        }

        for(int i = 0; i < words.size() - 1; i++)
        {   
            string word1 = words[i];
            string word2 = words[i + 1];

            int len = min(word1.size(), word2.size());
            if(word1.size() > word2.size() && word1.substr(0, len) == word2.substr(0, len))
            {
                return "";
            }
            int j = 0;
            while(j < len)
            {            
                if(word1[j] != word2[j])
                {
                    if(adj[word1[j]].find(word2[j]) == adj[word1[j]].end())
                    {
                        adj[word1[j]].insert(word2[j]);
                        indegree[word2[j]]++;
                    }
                    
                    break;
                }
                j++;
            }
        }
        queue<char> q;
        for(auto it: indegree)
        {
            if(it.second == 0)
            {
                q.push(it.first);
            }
        }

        string ans = "";
        while(!q.empty())
        {
            char letter = q.front();
            q.pop();

            ans += letter;

            for(auto it: adj[letter])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        return ans.size() == indegree.size() ? ans : "";
    }
};
