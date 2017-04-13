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