class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return calculateFrom(s, i);
    }
    
    int calculateFrom(string &s, int &i){
        int ret = 0, sign = 1, cur = 0;
        for (; i < s.size() && s[i] != ')'; i++){
            if (s[i] == ' ') continue;
            if (s[i] == '+' || s[i] == '-') {
                ret += sign * cur;
                sign = s[i] == '+'? 1 : -1;
                cur = 0;
            }
            else if (s[i] == '('){
                i++;
                cur = calculateFrom(s, i);
            }
            else cur = cur * 10 + s[i] - '0';
        }
        ret += sign*cur;
        return ret;
    }
};