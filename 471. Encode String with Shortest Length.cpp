class Solution {
public:
    string encode(string s) {
        vector<vector<string>> dp(s.size(), vector<string>(s.size(), ""));
        for (int len = 1; len <= s.size(); len++){
            for (int i = 0; i+len-1 < s.size(); i++){
                if (len < 5){  //too short don't need encode
                    dp[i][i+len-1] = s.substr(i, len);
                }
                else{
                    string best = "";
                    for (int j = i+1; j < i+len; j++){  //get best encode from substrs
                        if (best == "" || dp[i][j-1].size() + dp[j][i+len-1].size() < best.size())
                            best = dp[i][j-1] + dp[j][i+len-1];
                    }
                    string str = selfEncode(s, dp, i, len);  //check whether it has repeating substr
                    dp[i][i+len-1] = (str.size() < best.size() && str != "")? str:best;  //record the best encode
                }
            }
        }
        return dp[0][s.size()-1];
    }
    
    string selfEncode(string s, vector<vector<string>> &dp, int start, int len){
        string res = "";        
        for (int i = 1; i <= len/2; i++){
            if (len % i != 0) continue;
            string t = dp[start][start + i - 1];
            bool rpt = true;
            for (int j = 1; j < len/i; j++)
                if (dp[start + j*i][start + (j+1)*i - 1] != t){
                    rpt = false;
                    break;
                }
            if (rpt){
                string enco = to_string(len/i) + '[' + t + ']';
                if (res == "" || enco.size() < res.size()) 
                    res = enco;
            }
        }
        return res;
    }
};