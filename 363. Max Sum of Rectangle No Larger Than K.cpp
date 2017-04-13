class Solution {
public:
    //move left and right, calcu each row sum, find max subarray sum using set and lower_bound
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int res = INT_MIN, m = matrix.size(), n = matrix[0].size();
        for (int j = 0; j < n; j++){ //left bound
            vector<int> rowSum(m, 0); //row sum in [left, right]
            for (int l = j; l < n; l++){ //right bound
                for (int i = 0; i < m; i++) rowSum[i] += matrix[i][l]; //sum of each row in bound
                int prefix = 0;
                set<int> prefixSum;
                prefixSum.insert(0);
                for (int i = 0; i < m; i++) { //for each prefixSum, find the best previous prefixSum, so difference is subarray sum
                    prefix += rowSum[i];
                    auto comp = prefixSum.lower_bound(prefix - k);
                    if (comp != prefixSum.end()) res = max(res, prefix - *comp);
                    if (res == k) return k;
                    prefixSum.insert(prefix);
                }
            }
        }
        return res;
    }
};