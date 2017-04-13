class Solution {
public:
    int revtable[16] = { 0x0, 0x8, 0x4, 0xc, 0x2, 0xa, 0x6, 0xe, 0x1, 0x9, 0x5, 0xd, 0x3, 0xb, 0x7, 0xf};
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 4; i++){
            int r = (n >> 4*i) & 0xf;
            int l = (n >> 4*(7-i)) & 0xf;
            res |= (revtable[r] << 4*(7-i));
            res |= (revtable[l] << 4*i);
        }
        return res;
    }
};