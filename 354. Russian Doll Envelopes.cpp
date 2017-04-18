class Solution {
public:
    //sort, when first equals, put larger second in front of smaller second
    //find the longest increasing subsequence, with same first, this always update until second is smallest
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.empty()) return 0;
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](pair<int, int> a, pair<int, int> b){
           if (a.first != b.first) return a.first < b.first;
           else return a.second > b.second;
        });
        //below is 300. Longest Increasing Subsequence
        vector<int> dp;
        for (int i = 0; i < envelopes.size(); ++i) {
            auto itr = lower_bound(dp.begin(), dp.end(), envelopes[i].second);
            if (itr == dp.end()) {
                dp.push_back(envelopes[i].second);
            } else {
                *itr = envelopes[i].second;
            }
        }
        return dp.size();
    }
};