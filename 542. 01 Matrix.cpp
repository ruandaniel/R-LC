class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int dirs[4][2] = { { 1, 0 }, { -1, 0 }, { 0, -1 }, { 0, 1 } };
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == 1) matrix[i][j] = INT_MAX;
                else q.push({i, j});
            }
        }
        while (!q.empty()){
            auto t = q.front();
            q.pop();
            int x = t.first, y = t.second;
            for (int k = 0; k < 4; k++){
                int i = x + dirs[k][0], j = y + dirs[k][1];
                if (i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] <= matrix[x][y] + 1) continue;
                matrix[i][j] = matrix[x][y] + 1;
                q.push({i, j});
            }
        }
        return matrix;
    }
};