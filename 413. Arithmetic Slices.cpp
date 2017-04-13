class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        vector<int> dif;
        for (int i = 1; i < A.size(); i++) dif.push_back(A[i] - A[i-1]);
        int res = 0, c = 1;
        for (int i = 1; i < dif.size(); i++){
            if (dif[i] == dif[i-1]) c++;
            if (dif[i] != dif[i-1] || i == dif.size() - 1){
                c--;
                while (c) res += c--;
                c = 1;
            }
        }
        return res;
    }
};