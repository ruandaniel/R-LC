class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        //use hash table to record the divider-position
        unordered_map<int, int> m;
        //integer part
        string res = "";
        //deal with sign first in case of 
        if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) res += '-';
        long n = abs(long(numerator)); //may be abs INT_MIN
        long d = abs(long(denominator));
        res += to_string(n/d);
        long rem = n % d;
        if (rem == 0) return res;
        //decimal part
        res += '.';
        int start = res.size();
        for (int i = 0; rem; i++){
            rem *= 10;
            if (m.find(rem) != m.end()){
                return res.substr(0, start + m[rem]) + '(' + res.substr(start + m[rem]) + ')';
            }
            else{
                m[rem] = i;
            }
            res += to_string(rem/d);
            rem = rem % d;
        }
        return res;
    }
};