class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    bool solve(vector<vector<char>>& board){
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (int k = 0; k < 9; ++k) {
                        board[i][j] = '1' + k;
                        if (isValid(board, i, j) && solve(board))
                            return true;
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int x, int y){
        for (int k = 0; k < 9; k++){
            if (k != y && board[x][k] == board[x][y]) return false;
            if (k != x && board[k][y] == board[x][y]) return false;
        }
        int xx = x/3*3, yy = y/3*3; 
        for (int i = xx; i < xx+3; i++){
            for (int j = yy; j < yy+3; j++){
                if (i != x && j != y && board[i][j] == board[x][y]) return false;
            }
        }
        return true;
    }
};

//T=O(9^m), m is number of empty cells
