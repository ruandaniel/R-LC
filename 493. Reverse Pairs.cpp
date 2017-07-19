//Method 1: Merge Sort
//O(nlogn)
class Solution {
    //similar to #327
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
    
    int mergeSort(vector<int>& nums, int start, int end){
        if (!(start < end)) return 0;
        int div = (start + end) / 2;
        int count = mergeSort(nums, start, div) + mergeSort(nums, div + 1, end);
        int i = start, j = div + 1;
        //count the intersection part
        for (; i <= div; i++){
            while (j <= end && (long long)nums[j] * 2 < nums[i]) 
                j++;
            count += j - (div + 1);
        }
        //merge the two subs
        vector<int> cache;
        i = start; j = div + 1;
        for (int k = start; k <= end; k++){
            if (j > end || i <= div && (j <= end && nums[i] < nums[j])) 
                cache.push_back(nums[i++]);
            else 
                cache.push_back(nums[j++]);
        }
        for (int k = start; k <= end; k++) 
            nums[k] = cache[k - start];
        return count;
    }
};

