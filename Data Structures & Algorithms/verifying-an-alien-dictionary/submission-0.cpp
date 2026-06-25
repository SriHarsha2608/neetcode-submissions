class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mpp;
        for(int i = 0; i < 26; i++)
        {
            mpp[order[i]] = i;
        }

        int n = words.size();

        for(int i = 0; i < n - 1; i++)
        {
            string word1 = words[i], word2 = words[i + 1];

            int size = min(word1.size(), word2.size());
            bool foundDifference = false;

            for(int j = 0; j < size; j++)
            {
                if(word1[j] != word2[j])
                {
                    foundDifference = true;
                    if(mpp[word1[j]] > mpp[word2[j]])
                    {
                        return false;
                    }
                    else
                    {
                        break;
                    }
                }
                
            }

            if(!foundDifference)
            {
                if(word1.size() > word2.size())
                {
                    return false;
                }
            }
            
        }
        return true;
    }
};