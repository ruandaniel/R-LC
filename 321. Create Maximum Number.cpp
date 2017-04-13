class Solution {
public:
    //implement create maxnum using one array, then try all combinations of two arrays
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> res;
        for (int i = max(0, k-n2); i <= min(n1, k); i++){
            vector<int> l1 = getMax(nums1, i), l2 = getMax(nums2, k-i);
            vector<int> cur = merge(l1, l2);
            if (res.empty() || larger(cur, res)) res = cur;
        }
        return res;
    }
    //judge cur > pre? used for updating res as well as merging process
    bool larger(vector<int> &cur, vector<int> &pre){
        for (int i = 0; i < cur.size(); i++){
            if (i >= pre.size()) return true;
            if (cur[i] == pre[i]) continue;
            else if (cur[i] > pre[i]) return true;
            else return false;
        }
        return false;
    }
    //merge two arrays, be care of when l1[j] == l2[k], we need to pick the following larger one rather than randomly pick one
    vector<int> merge(vector<int> &l1, vector<int> &l2){
        vector<int> ret (l1.size() + l2.size(), 0);
        int j = 0, k = 0;
        for (int i = 0; i < l1.size() + l2.size(); i++){
            if (j == l1.size()) ret[i] = l2[k++];
            else if (k == l2.size()) ret[i] = l1[j++];
            else if (l1[j] > l2[k]) ret[i] = l1[j++];
            else if (l2[k] > l1[j]) ret[i] = l2[k++];
            else{
                vector<int> t1(l1.begin()+j, l1.end()), t2(l2.begin()+k, l2.end());
                if (larger(t1, t2)) ret[i] = l1[j++];
                else ret[i] = l2[k++];
            }
        }
        return ret;
    }
    //use stack to get max: while enough and larger? pop;
    vector<int> getMax(vector<int> &list, int k){
        if (k == 0) return {};
        vector<int> st;
        st.push_back(list[0]);
        int n = list.size();
        for (int i = 1; i < n; i++){
            while (n-i + st.size()-1 >= k && !st.empty() && list[i] > st.back()){
                st.pop_back();
            }
            if (st.size() < k) st.push_back(list[i]);
        }
        return st;
    }
};