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
        vector<Interval> res;
        int i;
        for (i = 0; i < intervals.size(); i++){ //store head part without intersect
            if (intervals[i].end >= newInterval.start) break;
            else res.push_back(intervals[i]);
        }
        
        if (intervals.empty() || intervals[i].start > newInterval.end) res.push_back(newInterval); //no intersect
        
        else{ //merging intersect part
            int start = newInterval.start, end = newInterval.end;
            for (;i < intervals.size(); i++){
                if (intervals[i].start > newInterval.end) break;
                start = min(start, intervals[i].start);
                end = max(end, intervals[i].end);
            }
            res.push_back(*(new Interval(start, end)));
        }
        
        for (;i < intervals.size(); i++){ //store tail part
            res.push_back(intervals[i]);
        }
    return res;   
    }
};