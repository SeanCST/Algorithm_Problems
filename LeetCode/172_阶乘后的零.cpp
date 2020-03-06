
//5*2 = 10出现一个0，n*(n-1)*(n-2)...1当中能被5整除的数少于能被2整除的数
//所以能被5整除的5的个数就是0的个数
//比如25！,25 = 5 * 5有两个5，20，15，10，5各含一个5，这六个5分别和2结合相乘就能得到末尾6个0
//所以只要count每个因子中5的个数就行

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while(n > 0){
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};


class Solution {
public:
    int trailingZeroes(int n) {
        long long factor = 5; // factor 由 5 变为 5^2, 5^3...
        int res = 0; // 用 res 记录所有数字中含因子 5 的个数
    
        while(n / factor) {
            res += n / factor; 
            factor *= 5;
        }

        return res;
    }
};