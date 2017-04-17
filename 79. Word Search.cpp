class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (find(board, i, j, word, 0, dirs)) return true;
            }
        }
        return false;
    }
    
    bool find(vector<vector<char>>& board, int x, int y, string &word, int start, vector<vector<int>> &dirs){
        if (word[start] != board[x][y]) return false;
        if (start == word.size() - 1) return true;
        char t = board[x][y];
        board[x][y] = ' ';
        for (int k = 0; k < 4; k++){
            int xx = x + dirs[k][0], yy = y + dirs[k][1];
            if (xx >= 0 && xx < board.size() && yy >= 0 && yy < board[0].size()){
                if (find(board, xx, yy, word, start + 1, dirs)) return true;
            }
        }
        board[x][y] = t;
        return false;
    }
};