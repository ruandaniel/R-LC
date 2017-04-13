class Solution {
public:
    //if want O(1) space, just rewrite the input's visited slots as a stack
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> st;
        int lower = INT_MIN;
        for (auto i : preorder){
            if (i <= lower) return false;
            if (st.empty() || i < st.top()){
                st.push(i);
            }
            else{
                while(!st.empty() && st.top() < i){
                    lower = st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return true;
    }
};