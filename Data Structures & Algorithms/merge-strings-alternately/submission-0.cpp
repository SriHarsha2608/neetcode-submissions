class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        int i = 0;
        string ans = "";
        while(i < 2*min(n, m))
        {
            if(i % 2 == 0)
            {
                ans += word1[i/2];
            }
            else
            {
                ans += word2[i/2];
            }
            i++;
        }
        if(n == min(n, m))
        {
            for(int i = n; i < m; i++)
            {
                ans += word2[i];
            }
        }
        else if(m == min(n, m))
        {
            for(int i = m; i < n; i++)
            {
                ans += word1[i];
            }
        }

        return ans;
    }
};