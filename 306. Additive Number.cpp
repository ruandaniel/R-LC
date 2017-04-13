class Solution {
public:
    //decide len of first two nums, then recursive check
    bool isAdditiveNumber(string num) {
        int n = num.size();
        if (n < 3) return false;
        for (int i = 1; i <= n/2; i++){
            int jRange = i + min((n-i)/2, n-2*i);
            for (int j = 1; j <= jRange; j++){
                if (check(num.substr(0, i), num.substr(i, j), num.substr(i+j))) return true;
            }
        }
        return false;
    }
    
    bool check(string num1, string num2, string rem){
        if ((num1.size() > 1 && num1[0] == '0') || (num2.size() > 1 && num2[0] == '0')) return false;
        string num3 = add(num1, num2);
        if (rem == num3) return true;
        if (rem.substr(0, num3.size()) != num3) return false;
        else return check(num2, num3, rem.substr(num3.size()));
    }
    
    string add(string s1, string s2){
        int c = 0;
        string ret = "";
        for (int i = 0; i < max(s1.size(), s2.size()); i++){
            int cur = c;
            if (i < s1.size()) cur += s1[s1.size() - 1 - i] - '0';
            if (i < s2.size()) cur += s2[s2.size() - 1 - i] - '0';
            c = cur / 10;
            ret += '0' + cur % 10;
        }
        if (c) ret += '0' + c;
        reverse(ret.begin(), ret.end());
        return ret;
    }
};