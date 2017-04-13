class Solution {
public:
    //The answer is between maximum value of input array numbers and sum of those numbers
    //set l = max, r = sum, and use BS to find mid
    //use greedy to split arrays to see whether it's possible, if yes, mid is too large, else too small
    int splitArray(vector<int>& nums, int m) {
        int l = INT_MIN, r = 0;
        for (auto num : nums){
            r += num;
            l = max(l, num);
        }
        while (l < r){
            int mid = l + (r - l) / 2;
            if (!canSplit(nums, m, mid)){
                l = mid + 1;
            }
            else r = mid;
        }
        return l;
    }
    
    bool canSplit(vector<int> &nums, int m, int mid){
        int cur = 0;
        for (auto num : nums){
            if (cur + num <= mid){
                cur += num;
            }
            else{
                m--;
                if (m == 0) return false;
                cur = num;
            }
        }
        return true;
    }
};