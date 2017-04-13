class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> m; //balance
        for (auto t : transactions){
            m[t[0]] -= t[2];
            m[t[1]] += t[2];
        }
        vector<int> bal;
        for (auto t : m){
            bal.push_back(t.second);
        }
        return helper(bal, 0);  //dfs
    }
    
    int helper(vector<int> &bal, int start){
        int notZero = start;
        for (; notZero < bal.size(); notZero++)  //find the first non-zero balance
            if (bal[notZero] != 0) break;
        if (notZero == bal.size()) return 0;
        int res = INT_MAX;
        for (int i = notZero + 1; i < bal.size(); i++){  //clear bal[notZero] with every non-zero and dif-sign bal[i], do dfs
            if (bal[i] == 0 || bal[i] * bal[notZero] > 0) continue;
            int t = bal[notZero];
            bal[notZero] = 0;
            bal[i] += t;
            res = min(res, 1 + helper(bal, notZero + 1));
            bal[i] -= t;
            bal[notZero] = t;
        }
        return res;
    }
};