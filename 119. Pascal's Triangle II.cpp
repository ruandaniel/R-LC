class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        vector<int> row(2, 1);
        for (int i = 2; i <= rowIndex; i++){
            for (int j = row.size()-1; j > 0; j--){
                row[j] += row[j-1];
            }
            row.push_back(1);
        }
        return row;
    }
};