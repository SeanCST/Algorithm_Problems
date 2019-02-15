class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int k = 1;
        while(k <= 32) {
            res = res * 2 + n % 2;
            n /= 2;
            k++;
        }
        
        return res;
    }
};


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int k = 32;
        while(k--){
            res <<= 1; // 左移一位
            res += n & 1;
            n >>= 1; // 右移一位
        }
        return res;
    }
};


