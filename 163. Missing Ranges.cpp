class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        long next = lower;
       
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] < next) continue;
            if (nums[i] == next) {
                next++;
                continue;;
            }
            res.push_back(getRange(next, nums[i]-1));
            next = long(nums[i])+1;
        }
        if (next <= upper) res.push_back(getRange(next, upper));
        return res;
    }
    string getRange(int start, int end)
    {
        return start==end? to_string(start) : to_string(start)+"->"+to_string(end);
    }
};