//Recursive
class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.empty() && p.empty()) return true;
        else if (p.empty()) return false;

        if (p[1] == '*'){
            if (p[0] != '.'){
                return isMatch(s, p.substr(2)) || (!s.empty() && s[0] == p[0] && isMatch(s.substr(1), p));
            }
            else{
                return isMatch(s, p.substr(2)) || (!s.empty() && isMatch(s.substr(1), p));
            }
        }
        else{
            return !s.empty() && (p[0] == '.' || s[0] == p[0]) && isMatch(s.substr(1), p.substr(1));
        }
    }
};

//DP
/*
dp[i][j] denotes s[0 : i-1] match p[0 : j-1]
if p[j - 1] != '*', dp[i][j] = true only if s[i-1] match p[j-1] && dp[i-1][j-1]
if p[j - 1] == '*', dp[i][j] = true only if :
    p[j-2:j-1] repeats 0 times: dp[i][j-2]
    or         repeats at least 1 time, that is, repeating part match with s[i-1] and p[0 : j-1] match s[0 : i-2]
               p[j - 2] match s[i - 1] && dp[i - 1][j]
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.empty() && p.empty()) return true;
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int j = 2; j < n + 1; j++) dp[0][j] = (p[j - 1] == '*' && dp[0][j - 2]);
        for (int i = 1; i < m + 1; i++){
            for (int j = 1; j < n + 1; j++){
                if (p[j - 1] != '*'){
                    dp[i][j] = (p[j - 1] == '.' || p[j - 1] == s[i - 1]) && dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = dp[i][j - 2] || (p[j - 2] == s[i - 1] || p[j - 2] == '.') && dp[i - 1][j];
                }
            }
        }
        return dp[m][n];
    }
};