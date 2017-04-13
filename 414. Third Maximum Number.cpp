class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for (auto num : nums) s.insert(num);
        if (s.size() < 3) return *(--s.end());
        else{
            auto it = s.end();
            it--; it--; it--;
            return *it;
        }
    }
};