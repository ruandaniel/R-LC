class Solution {
public:
    int findComplement(int num) {
        int len = 0;
        for (int i = 31; i >= 0; i--){
            if ((num>>i)){
                len = i+1;
                break;
            }
        }
        long t = (1<<len)-1;
        return ~num & t;
        // shoter version:
        // unsigned mask = ~0;
        // while (num & mask) mask <<= 1;
        // return ~mask & ~num;
    }
};