class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if (nums.size() < k) return 0;
        int sum = 0, res = INT_MIN;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if (i >= k) sum -= nums[i - k];
            if (i >= k - 1) res = max(res, sum);
        }
        return double(res) / k;
    }
};