//Method 1: 3D DP
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.empty() || M[0].empty()) return 0;
        int m = M.size(), n = M[0].size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(4, 0)));
        //each dp cell record all 4 dirs
        int res = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (!M[i][j]) continue;
                dp[i + 1][j + 1][0] = dp[i + 1][j][0] + 1;
                dp[i + 1][j + 1][1] = dp[i][j + 1][1] + 1;
                dp[i + 1][j + 1][2] = dp[i][j][2] + 1;
                dp[i + 1][j + 1][3] = j == n - 1? 1 : dp[i][j + 2][3] + 1;
                for (int k = 0; k < 4; k++) 
                    res = max(res, dp[i + 1][j + 1][k]);
            }
        }
        return res;
    }
};

//Method 2: 2D DP
//because cur line is only related with pre line, we can reduce 1 dimension
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.empty() || M[0].empty()) return 0;
        int m = M.size(), n = M[0].size();
        vector<vector<int>> pre(n, vector<int>(4, 0));
        vector<vector<int>> cur(n, vector<int>(4, 0));
        int res = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (!M[i][j]) {
                    for (int k = 0; k < 4; k++) cur[j][k] = 0;
                    continue;
                }
                cur[j][0] = j > 0 ? cur[j - 1][0] + 1 : 1;
                cur[j][1] = pre[j][1] + 1;
                cur[j][2] = j > 0 ? pre[j - 1][2] + 1 : 1;
                cur[j][3] = j < n - 1? pre[j + 1][3] + 1 : 1;
                for (int k = 0; k < 4; k++) 
                    res = max(res, cur[j][k]);
            }
            pre = cur;
        }
        return res;
    }
};