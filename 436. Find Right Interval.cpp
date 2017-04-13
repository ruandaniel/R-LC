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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        multiset<pair<int, int>> s;
        for (int i = 0; i < intervals.size(); i++) s.insert({intervals[i].start, i});
        vector<int> res(intervals.size(), 0);
        for (int i = 0; i < intervals.size(); i++){
            auto it = s.lower_bound({intervals[i].end, 0});
            if (it != s.end()){
                res[i] = it->second;
            }
            else res[i] = -1;
        }
        return res;
    }
};