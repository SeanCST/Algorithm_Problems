class Solution {
public:
    int addDigits(int num) {
        // f(x*10+y) = f(x*9+x+y) = f(x+y), 成立当 f(x) = x%9
        
        /** num = a * 10000 + b * 1000 + c * 100 + d * 10 + e
            num % 9 = (a + b + c + d + e) % 9 + (a * 9999 + b * 999 + c * 99 + d * 9) % 9
                    = (a + b + c + d + e) % 9
        **/
        return num == 0 ? 0 : (num % 9 == 0 ? 9 : num % 9);
        // return (num - 1) % 9 + 1;
    }
};

class Solution {
public:
    int addDigits(int num) {
        // X = 100*a + 10*b + c = 99*a + 9*b + (a+b+c)；所以对9取余即可。
        if(num % 9 == 0) {
            return num == 0 ? 0 : 9;
        } else {
            return num % 9;
        }
    }
};