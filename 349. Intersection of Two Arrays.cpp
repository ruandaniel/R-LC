class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> m;
        unordered_map<int, bool> existed;
        for (auto it : nums1) m[it] = true;
        vector<int> res;
        for (auto it : nums2)
            if (!existed[it] && m[it]){
                existed[it] = true;
                res.push_back(it);
            }
        
        return res;
    }
};