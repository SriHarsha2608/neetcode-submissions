class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        int ans = n;

        int i = 1;
        while(i < n) {
            while(i < n && ratings[i] == ratings[i - 1]) i++;

            int peak = 0;

            while(i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                ans += peak;
                i++;
            }

            int valley = 0;
            while(i < n && ratings[i] < ratings[i - 1]) {
                valley++;
                ans += valley;
                i++;
            }

            ans -= min(peak, valley);
        }

        return ans;
    }
};