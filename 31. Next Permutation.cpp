class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int firstDown = -1, firstBigger;
        // From right to left, find the first digit(partitionNumber) 
        // which violates the increase trend
        for (int i = nums.size()-2; i >= 0; i--){
            if (nums[i] < nums[i+1]) {
                firstDown = i;
                break;
            }
        }
        if (firstDown == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        // From right to left, find the first digit which is greater
        // than the partition number, call it changeNumber
        for (int i = nums.size()-1; i > firstDown; i--){
            if (nums[i] > nums[firstDown]) {
                firstBigger = i;
                break;
            }
        }
        swap(nums[firstDown], nums[firstBigger]);
        // Reverse all the digits on the right of partitionNumber
        reverse(nums.begin() + firstDown+1, nums.end());
    }
};