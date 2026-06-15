class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const vector<int>&a,const vector<int>&b){
            return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1];
        };
        priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)>maxPq(cmp);
        for(auto point:points){
            maxPq.push(point);
            if(maxPq.size()>k)maxPq.pop();
        }
        vector<vector<int>> result;
        while(!maxPq.empty()){
            result.push_back(maxPq.top());
            maxPq.pop();
        }
        return result;
    }
};
