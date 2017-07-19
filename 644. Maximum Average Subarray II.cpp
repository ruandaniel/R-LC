//Method 1: move right bound, try every subarray, update max avg and its correspond left bound
//worst case O(n^2)
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for (int i = 0; i < k; i++){
            sum += nums[i];
        }
        double avg = double(sum) / k, res = avg;
        int len = k;
        for (int i = k; i < nums.size(); i++){
            sum += nums[i];
            avg = sum / (++len);
            double curSum = sum, curAvg = avg;
            for (int j = len - 1; j >= k; j--){//subtract from left, one by one
                curSum -= nums[i - j]; //cur length--, that is exactly j
                curAvg = curSum / j;
                if (curAvg >= avg){ //if a suffix subarray has new peak avg, we no longer need to consider the nums before it
                    sum = curSum;
                    avg = curAvg;
                    len = j;
                }
            }
            if (avg > res) res = avg;
        }
        return res;
    }
};

//Method 2: Binary search
//assume a possible number as avg, try to check whether we can find a sub that avg >= this number
//then ajust the bound until precision requirement met
//O(nlog(max num - min num))
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double h = INT_MIN, l = INT_MAX;
        for (auto num : nums){
            if (num > h) h = num;
            if (num < l) l = num;
        }
        double mid, lastMid = h, error = INT_MAX;
        while (error > 0.00001){
            mid = l + (h - l) / 2;
            if (check(nums, mid, k)) l = mid;
            else h = mid;
            error = abs(mid - lastMid);
            lastMid = mid;
        }
        return mid;
    }
    
    //to check whether we can find a sub that avg >= mid 
    bool check(vector<int>& nums, double mid, int k){
        //subtract each num with mid, so if any sub sum >= 0, return true
        double minPrefix = 0, prefix = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i] - mid;
            if (i < k - 1) continue;
            if (i >= k){
                prefix += nums[i - k] - mid;
                if (prefix < minPrefix) minPrefix = prefix; //update min prefix sum
            }
            if (sum - minPrefix >= 0) return true; //cur total sum - min prefix sum >= 0 means found a sub sum >= 0
        }
        return false;
    }
};