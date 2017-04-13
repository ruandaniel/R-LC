class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num < 1) return false;
        while (num >> 2){
            if (num & 3) return false;
            num >>= 2;
        }
        if (num != 1) return false;
        return true;
    }
};