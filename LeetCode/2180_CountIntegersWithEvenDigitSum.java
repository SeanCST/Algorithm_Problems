class Solution {
    public int countEven(int num) {
        if((num & 1) == 1) {
            return num / 2;
        }

        int t = num / 10, s = 0;
        while(t != 0) {
            s += t % 10;
            t /= 10;
        }
        return num / 2 - (s & 1);
    }
}