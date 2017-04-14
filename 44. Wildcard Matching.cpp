//Greedy:
class Solution {
public:
    //use two pointers to move, when meet *, mark it and mark the pos in s, cur match fail, go back to mark and move pos in s
    bool isMatch(string s, string p) {
        int is = 0, ip = 0, star = -1, mark = 0;
        while (is < s.size()){
            //if cur char match, both move 1
            if (ip < p.size() && (s[is] == p[ip] || p[ip] == '?')){
                is++;
                ip++;
                continue;
            }
            //not match, check is *? if yes, update star and mark
            if (ip < p.size() && p[ip] == '*'){
                star = ip++;
                mark = is;
                continue;
            }
            //not match and not a *, go back to ++mark
            if (star != -1){
                is = ++mark;
                ip = star+1;
                continue;
            }
            //if no star and not match, false
            return false;
            //if mark and is reach the end, will jump out of the loop
        }
        //skip the remaining *
        while (ip < p.size() && p[ip] == '*') ip++;
        //if ip reach the end too, true
        return ip == p.size();
    }
};

//DP, Similar to Regular Expression LC10
class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.empty() && p.empty()) return true;
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int j = 1; j < n + 1 && p[j - 1] == '*'; j++) dp[0][j] = true;
        for (int i = 1; i < m + 1; i++){
            for (int j = 1; j < n + 1; j++){
                if (p[j - 1] != '*'){
                    dp[i][j] = (p[j - 1] == '?' || p[j - 1] == s[i - 1]) && dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = dp[i][j-1] || dp[i-1][j]; 
                }
            }
        }
        return dp[m][n];
    }
};

//to reduce space: simple way, record dp[i-1][] so that O(n) space; or the following code
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<bool> cur(m + 1, false); 
        cur[0] = true;
        for (int j = 1; j <= n; j++) {
            bool pre = cur[0]; // use the value before update
            cur[0] = cur[0] && p[j - 1] == '*'; 
            for (int i = 1; i <= m; i++) {
                bool temp = cur[i]; // record the value before update
                if (p[j - 1] != '*')
                    cur[i] = pre && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
                else cur[i] = cur[i - 1] || cur[i];
                pre = temp;
            }
        }
        return cur[m]; 
    }
};





