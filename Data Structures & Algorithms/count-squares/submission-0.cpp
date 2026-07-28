class CountSquares {
private:
    map<pair<int, int>, int> mpp;
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        mpp[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int ans = 0;

        for(auto it: mpp) {
            int dx = it.first.first, dy = it.first.second;
            int count = it.second;

            if(abs(dx - x) != abs(dy - y) || dx == x || dy == y) {
                continue;
            }

            if(mpp.find({x, dy}) != mpp.end() && mpp.find({dx,y}) != mpp.end()) {
                ans += count * mpp[{x, dy}] * mpp[{dx, y}];
            }
        }

        return ans;
    }
};
