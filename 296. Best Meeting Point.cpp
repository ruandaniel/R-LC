class Solution {
public:
    //if you have different numbers of people on your left and on your right
    //moving a little to the side with more people decreases the sum of distances
    //find the median
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