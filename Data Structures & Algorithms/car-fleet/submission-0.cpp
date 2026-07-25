class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> car(n);
        for(int i = 0; i < n; i++) {
            car[i] = {position[i], speed[i]};
        }
        sort(car.rbegin(), car.rend());

        int fleets = 1;
        double prevTime = (double) (target - car[0].first) / car[0].second;

        for(int i = 1; i < n; i++) {
            double curTime = (double) (target - car[i].first) / car[i].second;
            if(curTime > prevTime) {
                fleets++;
                prevTime = curTime;
            }
        }

        return fleets;
    }
};
