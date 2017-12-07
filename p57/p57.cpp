/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res(intervals);

        int n = intervals.size(), i = 0, overlap = 0;
        while (i < n)
        {
        	if (newInterval.start > intervals[i].end)
        		++i;
        	else
        	if (newInterval.end < intervals[i].start)
        		break;
        	else
        	{
        		newInterval.start = min(newInterval.start,intervals[i].start);
        		newInterval.end = max(newInterval.end,intervals[i].end);
        		++overlap;
        		++i;
        	}
        }

        res.erase(res.begin() + i - overlap, res.begin() + i);
        res.insert(res.begin() + i - overlap, newInterval);

        return res;
    }
};
