class Solution {
public:
    bool isHappy(int n) {
        map<int, bool> m;
        while(n != 1) {
            if(m[n] == true) return false;
            m[n] = true;
            int temp = 0;
            while(n > 0) {
                int mod = n % 10;
                temp += mod * mod;
                n /= 10;
            }
            n = temp;
        }
        
        return true;
    }
};