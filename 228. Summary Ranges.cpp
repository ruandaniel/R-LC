class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int l = 0, r = 0;
        vector<string> res;
        while(r < nums.size()){
            while(r < nums.size() - 1 && nums[r + 1] == nums[r] + 1) r++;
            if (r > l) {
				string s = to_string(nums[l]) + "->" + to_string(nums[r]);
				res.push_back(s);
			}
            else res.push_back(to_string(nums[r]));
            l = r + 1;
            r++;
        }
        return res;
    }
};