class Solution {
public:
    int minSteps(int n) {
        int res = 0, d = 2;

        while(n > 1) {
            while(n % d == 0) {
                res += d;
                n /= d;
            }
            d++;
        }

        return res;
    }
};

class Solution {
public:
    int minSteps(int n) {
        if(n <= 1) {
            return 0;
        }
        int minFactor = 1;
        for(int i = 2; i <= sqrt(n); i++) {
            if(n % i == 0) { // 找到大于等于2的最小因数
                minFactor = i;
                break;
            }
        }

        if(minFactor == 1) { 
            return n;
        }
        // minFactor：把当前字符串复制粘贴达到结果所需要的次数
        // minSteps(n / minFactor)：达到当前字符串所需要的次数
        return minFactor + minSteps(n / minFactor);
    }
};