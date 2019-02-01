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