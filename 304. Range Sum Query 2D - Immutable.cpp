class NumMatrix {
public:
    //pre-compute the region sum of (0, 0) to (i, j), O(mn) time, so the query take O(1) time
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>> matrix) {
        if (!(matrix.empty() || matrix[0].empty())){
            int m = matrix.size();
            int n = matrix[0].size();
            sum.resize(m+1, vector<int>(n+1, 0));
            for (int i = 0; i < m; i++){
                int cur = 0;
                for (int j = 0; j < n; j++){
                    cur += matrix[i][j];
                    sum[i+1][j+1] = sum[i][j+1] + cur;
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int t = sum[row1][col2+1] + sum[row2+1][col1] - sum[row1][col1];
        return sum[row2+1][col2+1] - t;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */