class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int i = 1; i <= n/2; i++){
            if (n % i) continue;
            bool isRpt = true;
            string rpt = s.substr(0, i);
            for (int j = 1; j < n/i; j++){
                if (rpt != s.substr(i*j, i)) {
                    isRpt = false;
                    break;
                }
            }
            if (isRpt) return true;
        }
        return false;
    }
};