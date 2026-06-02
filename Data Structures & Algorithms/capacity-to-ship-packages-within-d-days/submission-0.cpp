class Solution {
public:

    bool canShip(vector<int>& weights, int days, int max)
    {
        int usedDays = 1;
        int sum = 0;
        for(int weight: weights)
        {
            if(sum + weight > max)
            {
                usedDays++;
                sum = 0;
            }
            sum += weight;
        }
        return days >= usedDays;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end()), high = accumulate(weights.begin(), weights.end(), 0);
        int ans = 1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(canShip(weights, days, mid))
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