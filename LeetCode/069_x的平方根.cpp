class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) {
            return x;
        }
        
        int64_t r = x;
        while(r > x / r) {
            r = (r + x / r) / 2;
        } 

        return r;
    }
};

class Solution {
public:
    int mySqrt(int x) {
        int i = 1;
        while(i < x){
            if ((i * i <= x) && ((i + 1) * (i + 1) > x)) {
                return i;
            }
            i++;
        }
        
        return i;
    }
};