class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto midptr = nums.begin() + n / 2; //get median
        nth_element(nums.begin(), midptr, nums.end());
        int median = *midptr;
        int left = 0, i = 0, right = n - 1;
        while (i <= right) { //sort colors, put larger on the left, smaller on the right
            if (nums[newIndex(i,n)] > median) {
                swap(nums[newIndex(left++,n)], nums[newIndex(i++,n)]);
            }
            else if (nums[newIndex(i,n)] < median) {
                swap(nums[newIndex(right--,n)], nums[newIndex(i,n)]);
            }
            else {
                i++;
            }
        }
    }
    int newIndex(int i, int n){ 
        //index mapping, target:
        //M M ... S S S S
        // L L ... L M M
        //so we have ML..SLSL..SMSM(S) which meets wiggle
        if (1 + 2 * i < n) return (1 + 2 * i) % n;
        else if (n % 2) return (1 + 2 * i) % n;
        else return (2 * i) % n;
    }
   
};