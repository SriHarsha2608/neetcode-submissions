/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> times;

        for(auto it: intervals)
        {
            times.push_back({it.start, 0});
            times.push_back({it.end, -1});
        }

        sort(times.begin(), times.end());

        int maxCount = 0;
        int count = 0;

        for(auto &[time, pos]: times)
        {
            if(pos == 0)
            {
                count++;
                maxCount = max(count, maxCount);
            }
            else
            {
                count--;
            }
        }

        return maxCount;
    }
};
