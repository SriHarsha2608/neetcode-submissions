class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        int leftMax = -1, rightMax = -1;
        int maxSize = 0;
        int count = 0;

        for(int i = 0; i < n; i++)
        {
            int left = i, right = i;
            while(left >= 0 && right < n)
            {
                if(s[left] == s[right])
                {
                    // int size = right - left + 1;

                    // if(size > maxSize)
                    // {
                    //     maxSize = size;
                    //     leftMax = left;
                    //     rightMax = right;
                    // }
                    count++;

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
                //    int size = right - left + 1;
                    
                //     if(size > maxSize)
                //     {
                //         maxSize = size;
                //         leftMax = left;
                //         rightMax = right;
                //     }
                    count++;

                    left--;
                    right++;
                }
                else
                {
                    break;
                }
            }
        }

        // return s.substr(leftMax, maxSize);
        return count;
    }
};
