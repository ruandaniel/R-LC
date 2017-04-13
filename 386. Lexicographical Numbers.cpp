class Solution {
public:
    vector<int> lexicalOrder(int n) {
        if (n == 0) return {};
        int cur = 1;
        vector<int> res;
        for (int i = 1; i <= n; i++){
            res.push_back(cur);
            if (cur * 10 <= n){ //add 0 to the tail
                cur *= 10;
            }
            else if (cur % 10 != 9 && cur + 1 <= n){ //not ending with 9 and +1 in bound
                cur++;
            }
            else{ //ending with 9 / out of bound: delete all 9s and increase 1 / divide by 10 until in bound-1
                while (cur % 10 == 9 || cur >= n) cur /= 10;
                cur++;
            }
        }
        return res;
    }
};