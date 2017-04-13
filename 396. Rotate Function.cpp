class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n = A.size();
        int cur = 0, res, sum = 0;
        for (int i = 0; i < n; i++){
            cur += i*A[i];
            sum += A[i];
        }
        res = cur;
        for (int i = n-1; i >= 1; i--){
            cur = cur + sum - n * A[i];
            res = max(res, cur);
        }
        return res;
    }
};