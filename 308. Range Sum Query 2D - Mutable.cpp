class NumMatrix {
    vector<vector<int>> matrix;
    vector<vector<int>> rowPrefix;
public:
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        this->matrix = matrix;
        rowPrefix.resize(matrix.size(), vector<int>(matrix[0].size()+1, 0));
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++){
                rowPrefix[i][j+1] = rowPrefix[i][j] + matrix[i][j];
            }
    }
    
    void update(int row, int col, int val) {
        matrix[row][col] = val;
        for (int j = col; j < matrix[0].size(); j++){
            rowPrefix[row][j+1] = rowPrefix[row][j] + matrix[row][j];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; i++){
            sum += rowPrefix[i][col2+1] - rowPrefix[i][col1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */