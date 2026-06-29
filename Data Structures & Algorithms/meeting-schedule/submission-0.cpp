/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this.start = start;
 *         this.end = end;
 *     }
 * }
 */

class Solution {
private:
    static bool cmp(const Interval &a, const Interval &b)
    {
        if(a.start == b.start)
        {
            return a.end < b.end;
        }

        return a.start < b.start;
    }
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int startTime = intervals[0].start, endTime = intervals[0].end;
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i].start < endTime)
            {
                return false;
            }
            endTime = intervals[i].end;
        }

        return true;
    }
};
