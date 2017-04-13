class Solution {
public:
    bool isNumber(string s) {
        //delete leading and tail space
        int start = 0, end = s.size()-1;
        while (s[start] == ' ') start++;
        while (s[end] == ' ') end--;
        s = s.substr(start, end-start+1);
        
        bool eSeen = false, pointSeen = false, numberSeen = false, numberAfterE = false;
        
        for (int i = 0; i < s.size(); i++){
            if (s[i] >= '0' && s[i] <= '9'){
                numberSeen = true;
                if (eSeen) numberAfterE = true;
            }
            else if (s[i] == '.'){
                if (eSeen || pointSeen) return false; //no e before . and no more than 1 .
                pointSeen = true;
            }
            else if (s[i] == 'e'){ //e must after number and no more than 1 e
                if (eSeen || !numberSeen) return false;
                eSeen = true;
            }
            else if (s[i] == '-' || s[i] == '+'){ //+-must be before num or after e
                if (i != 0 && s[i-1] != 'e') return false;
            }
            else return false;
        }
        if (!numberSeen) return false;
        else return !eSeen || (eSeen && numberAfterE);
    }
};

//T=O(n)