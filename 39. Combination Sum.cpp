class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        vector<vector<int>> res;
        helper(candidates, cur, res, 0, target);
        return res;
    }
    
    void helper(vector<int>& candidates, vector<int> &cur, vector<vector<int>> &res, int start, int target){
        if (target == 0) res.push_back(cur);
        else{
            for (int i = start; i < candidates.size(); i++){
                if (candidates[i] > target) return;
                cur.push_back(candidates[i]);
                helper(candidates, cur, res, i, target - candidates[i]);
                cur.pop_back();
            }
        }
    }
};