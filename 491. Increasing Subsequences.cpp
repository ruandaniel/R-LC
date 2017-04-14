class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> res;
        helper(nums, res, cur, 0);
        return res;
    }
    
    //skip dup in each recursion
    void helper(vector<int>& nums, vector<vector<int>> &res, vector<int> &cur, int start){
        if (cur.size() > 1) res.push_back(cur);
        unordered_set<int> used;
        for (int i = start; i < nums.size(); i++){
            if ((cur.empty() || nums[i] >= cur.back()) && used.find(nums[i]) == used.end()){
                used.insert(nums[i]);
                cur.push_back(nums[i]);
                helper(nums, res, cur, i + 1);
                cur.pop_back();
            }
        }
    }
};