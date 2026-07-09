class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0), cur(n, 0);
        prev[0] = 1;

        for(int i = 0; i < m; i++)
        {
            vector<int> cur(n, 0);
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0)
                {
                    cur[j] = 1;
                    continue;
                }                
                if(i > 0)
                {
                    cur[j] += prev[j];
                }
                if(j > 0)
                {
                    cur[j] += cur[j - 1];
                }
            }
            prev = cur;
        }
        return prev[n - 1];
    }
};
