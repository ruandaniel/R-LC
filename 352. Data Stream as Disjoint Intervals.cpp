/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    set<pair<int, int>> cache;
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        auto it = cache.lower_bound({val, val});
        if (it->first == val) return;
        else if (it == cache.begin()){
            if (it->first == val + 1) {
                cache.insert({val, it->second});
                cache.erase(it);
            }
            else cache.insert({val, val});
        }
        else{
            auto pre = it;
            pre--;
            if (pre->second >= val) return;
            if (pre->second == val - 1 && it->first == val + 1){
                cache.insert({pre->first, it->second});
                cache.erase(pre);
                cache.erase(it);
            }
            else if (pre->second == val - 1){
                cache.insert({pre->first, val});
                cache.erase(pre);
            }
            else if (it->first == val + 1){
                cache.insert({val, it->second});
                cache.erase(it);
            }
            else{
                cache.insert({val, val});
            }
        }
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> res;
        for (auto i : cache){
            res.push_back(*(new Interval(i.first, i.second)));
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */