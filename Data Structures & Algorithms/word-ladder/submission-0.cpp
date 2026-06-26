class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        if(st.find(endWord) == st.end())
        {
            return 0;
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        if(st.find(beginWord) != st.end()) st.erase(beginWord);
        
        while(!q.empty())
        {
            string node = q.front().first;
            string word = node;
            int steps = q.front().second;

            q.pop();

            if(node == endWord)
            {
                return steps;
            }

            for(int i = 0; i < word.size(); i++)
            {
                for(char j = 'a'; j <= 'z'; j++)
                {
                    word[i] = j;

                    if(st.find(word) != st.end())
                    {
                        q.push({word, steps + 1});
                        st.erase(word);
                    }
                }
                word = node;
            }
        }

        return 0;
    }
};
