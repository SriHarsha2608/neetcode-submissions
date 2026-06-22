class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }

        for(int i = 0; i < n; i++)
        {
            int left = i, right = i;
            while(left >= 0 && right < n)
            {
                if(s[left] == s[right])
                {
                    dp[left][right] = true;
                    left--;
                    right++;
                }
                else
                {
                    break;
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            int left = i, right = i + 1;
            while(left >= 0 && right < n)
            {
                if(s[left] == s[right])
                {
                    dp[left][right] = true;
                    left--;
                    right++;
                }
                else
                {
                    break;
                }
            }
        }

        int leftMax = -1, rightMax = -1;
        int maxSize = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(dp[i][j] == true)
                {
                    int size = j - i + 1;
                    if(size > maxSize)
                    {
                        maxSize = size;
                        leftMax = i;
                        rightMax = j;
                    }
                }
            }
        }
        
        // return string(s.begin() + leftMax, s.begin() + rightMax);
        return s.substr(leftMax, maxSize);

    }
};
