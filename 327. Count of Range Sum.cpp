class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        if (n == 0 || lower > upper) return 0;
        vector<long> prefixSum(n + 1, 0); //pre compute
        for (int i = 1; i <= n; i++) prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        return mergeSort(prefixSum, 1, n, lower, upper);
    }
    
    int mergeSort(vector<long> &prefixSum, int start, int end, int lower, int upper){
        if (start > end) return 0;
        if (start == end) return (prefixSum[start] >= lower && prefixSum[start] <= upper)? 1 : 0;
        int mid = start + (end - start)/2;
        int ret = mergeSort(prefixSum, start, mid, lower, upper) + mergeSort(prefixSum, mid + 1, end, lower, upper);
        int left = mid + 1, right = mid + 1;
        for (int i = start; i <= mid; i++){ //deal with the intersect part
            //find the range that for ith ele in left part, sum in right part - sum[i] is in bound
            //important: left and right no need to reset every time, because with i++, left & right must not decrease
            while (left <= end && prefixSum[left] - prefixSum[i] < lower) left++;
            while (right <= end && prefixSum[right] - prefixSum[i] <= upper) right++;
            ret += right - left;
        }
        vector<long> temp; //merge the two part in cache
        for (int k = start, i = start, j = mid + 1; k <= end; k++){
            if (i <= mid && (j > end || prefixSum[i] < prefixSum[j])) temp.push_back(prefixSum[i++]);
            else temp.push_back(prefixSum[j++]);
        }
        for (int k = 0; k < temp.size(); k++) prefixSum[start + k] = temp[k]; //copy to memory
        return ret;
    }
};