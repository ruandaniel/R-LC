class Solution {
public:
    //If current character is '(', push its index to the stack. 
	//If current character is ')' and the top of stack is '(', we find matching pair so pop from the stack. 
	//Otherwise, we push the index of ')' to the stack.
    //finally, the stack will only contain the indices of characters which cannot be matched
    int longestValidParentheses(string s) {
        if (s.empty()) return 0;
        stack<int> st;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(') st.push(i);
            else if (!st.empty() && s[st.top()] == '(') st.pop();
            else st.push(i);
        }
        if (st.empty()) return s.size();
        int pre = st.top();
        int res = s.size() - pre - 1; //tail part
        st.pop();
        while (!st.empty()){
            res = max(res, pre - st.top() - 1);
            pre = st.top();
            st.pop();
        }
        res = max(res, pre); //head part
        return res;
    }
};

//T = O(n)
