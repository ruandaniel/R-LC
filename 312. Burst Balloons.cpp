class Solution {
public:
    //bottom to top DP, increment the bounds distance
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 2; len < n; len++){ //distance between left and right bound
            for (int leftBound = 0; leftBound < n - len; leftBound++){
                int rightBound = leftBound + len; //bound balloon will not be bursted
                for (int final = leftBound + 1; final < rightBound; final++){ 
                    //pick a balloon to be the final bursted one, regarded as a bound too, so this will divide the range into two
                    int cur = nums[leftBound] * nums[final] * nums[rightBound] + dp[leftBound][final] + dp[final][rightBound];
                    dp[leftBound][rightBound] = max(dp[leftBound][rightBound], cur);
                }
            }
        }
        return dp[0][n-1];
    }
};