class Solution {
public:
    //^all, we get a^b, find one bit that they differ, use this bit to divide arrays into two groups
    vector<int> singleNumber(vector<int>& nums) {
        int product = 0;
        for (auto num : nums) product ^= num;
        int differ;
        for (int i = 0; i < 32; i++){
            if (product & (1 << i)){
                differ = i;
                break;
            }
        }
        int res1 = 0, res2 = 0;
        for (auto num : nums){
            if (num & (1 << differ)) res1 ^= num;
            else res2 ^= num;
        }
        return {res1, res2};
    }
};