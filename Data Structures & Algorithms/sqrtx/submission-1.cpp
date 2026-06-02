class Solution {
public:
    int mySqrt(int x) {
        int low = 0, high = x;
        int ans = -1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            long long int sq = (long long)mid * mid;
            if(sq <= x)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};