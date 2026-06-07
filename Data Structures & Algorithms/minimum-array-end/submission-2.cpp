class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        long long left = 1, right = 1;

        while(right <= n - 1)
        {
            if((left & x) == 0)
            {
                if(right & (n - 1))
                {
                    ans = ans | left;
                }
                right = right << 1;
            }
            left = left << 1;
        }
        return ans;
    }
};