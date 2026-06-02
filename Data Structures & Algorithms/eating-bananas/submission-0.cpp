class Solution {
public:
    bool canEat(vector<int>& piles, int h, int k)
    {
        for(int pile: piles)
        {
            h -= (pile + k - 1) / k;
            if(h < 0)
            {
                return false;
            }
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = 1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(canEat(piles, h, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};
