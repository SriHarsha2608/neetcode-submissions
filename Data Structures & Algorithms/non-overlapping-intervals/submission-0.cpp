class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int ans = 0;
        int start = intervals[0][0], end = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] < end)
            {
                ans++;
                end = min(end, intervals[i][1]);
            }
            else
            {
                // ans++;
                start = intervals[i][0];
                end = intervals[i][1];
            }
        
        } 
        

        return ans;
    }
};
