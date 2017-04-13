class Solution {
public:
	//when meet a sign, deal with prev sign and prev number, record the prev num or product
    int calculate(string s){
        if (s.empty()) return 0;
	    int cur = 0, res = 0, num = 0; //num is cur num, cur is prev product
	    char sign = '+';
	    for (int i = 0; i < s.size(); i++){
	        if (s[i] == ' ' && i < s.size()-1) continue;
	        if (s[i] >= '0' && s[i] <= '9'){
	            num = num*10 + s[i] - '0';
	        }
	        if (!(s[i] >= '0' && s[i] <= '9') || i == s.size()-1){
    	        if (sign == '+' || sign == '-') {
    	            cur = (sign == '+'? num : -num);
    	            res += cur;
    	        }
    	        else{
    	            res -= cur;
    	            cur = (sign == '*'? cur * num : cur / num);
    	            res += cur;
    	        }
    	        num = 0;
    	        sign = s[i];
	        }
	    }
	    return res;
	}
};