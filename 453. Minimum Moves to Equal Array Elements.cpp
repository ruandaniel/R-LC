class Solution {
public
    n-1 eles + 1 is the same as the other one ele - 1
    int minMoves(vectorint& nums) {
        int m = INT_MAX;
        for (auto num  nums) m = min(m, num);
        int res = 0;
        for (auto num  nums) res += num-m;
        return res;
    }
};