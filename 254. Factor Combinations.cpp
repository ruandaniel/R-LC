class Solution {
public:
    //DFS, pass the starting factor as a parameter
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> cur;
        DFS(n, cur, res, 2);
        return res;
    }
    
    void DFS(int n, vector<int> &cur, vector<vector<int>> &res, int start){
        for (int i = start; i <= sqrt(n); i++){
            if (n % i == 0){
                //push i and n/i, store, then retrieve n/i and continue
                cur.push_back(i);
                cur.push_back(n/i);
                res.push_back(cur);
                cur.pop_back();
                DFS(n/i, cur, res, i);
                cur.pop_back();
            }
        }
    }
};