class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2 && nums[i] <= 0; i++){ //when nums[i] > 0, impossible
            if (i != 0 && nums[i] == nums[i - 1]) continue; //avoid dup
            int j = i + 1, k = nums.size() - 1;
            int target = -nums[i];
            //then is two sum
            while (j < k){
                int sum = nums[j] + nums[k];
                if (sum < target){
                    j++;
                }
                else if (sum > target){
                    k--;
                }
                else{
                    res.push_back({nums[i], nums[j++], nums[k--]});
                    //below avoid dup
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return res;
    }
};

//O(n^2)