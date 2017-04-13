class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        int l = 1, r = num / 2;
        while (l <= r){
            int mid = l + (r - l) / 2;
            long p = long(mid) * mid; //long important
            if (p == num) return true;
            else if (p > num) r = mid - 1;
            else l = mid + 1;
        }
        return false;

    }
};