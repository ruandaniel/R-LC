//if you have different numbers of people on your left and on your right
//moving a little to the side with more people decreases the sum of distances
//find the median

//Method 1: collect sum, find mid for row and col, calculate distance
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size(), total = 0;
        vector<int> row(m, 0), col(n, 0);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1){
                    row[i]++;
                    col[j]++;
                    total++;
                }
            }
        }
        int rowMid, colMid, count = 0;
        for (int i = 0; i < m; i++){
            count += row[i];
            if (count > total/2){
                rowMid = i;
                break;
            }
        }
        count = 0;
        for (int j = 0; j < n; j++){
            count += col[j];
            if (count > total/2){
                colMid = j;
                break;
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++) res += row[i]*abs(i-rowMid);
        for (int j = 0; j < n; j++) res += col[j]*abs(j-colMid);
        return res;
    }
};
//T = O(m*n), S = O(m+n)

//Method 2: collect sum, from two end, pair one with one, sum distance
class Solution{
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row(m, 0), col(n, 0);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                row[i] += grid[i][j];
                col[j] += grid[i][j];
            }
        }
        int res = 0;
        int i = 0, j = m - 1;
        while (i < j){
            int cur = min(row[i], row[j]);
            row[i] -= cur;
            row[j] -= cur;
            res += cur * (j - i);
            while (i < j && row[i] == 0) i++;
            while (i < j && row[j] == 0) j--;
        }
        i = 0; j = n - 1;
        while (i < j){
            int cur = min(col[i], col[j]);
            col[i] -= cur;
            col[j] -= cur;
            res += cur * (j - i);
            while (i < j && col[i] == 0) i++;
            while (i < j && col[j] == 0) j--;
        }
        return res;
    }
};