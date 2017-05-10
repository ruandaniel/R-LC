//DP[i][j] means max days up to ith day in city j, -1 means not accessible
class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int numOfCity = flights.size(), numOfDays = days[0].size();
        vector<vector<int>> dp(numOfDays + 1, vector<int> (numOfCity, -1));
        dp[0][0] = 0;
        for (int i = 1; i <= numOfDays; i++){
            for (int j = 0; j < numOfCity; j++){
                if (dp[i - 1][j] < 0) continue;
                for (int k = 0; k < numOfCity; k++){
                    if (k == j || flights[j][k]){
                        dp[i][k] = max(dp[i][k], dp[i - 1][j] + days[k][i - 1]);
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < numOfCity; i++){
            res = max(res, dp[numOfDays][i]);
        }
        return res;
    }
};