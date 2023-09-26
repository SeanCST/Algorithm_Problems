class Solution {
    public int passThePillow(int n, int time) {
        int round = time / (n - 1);
        int mod = time % (n - 1);
        if(round % 2 == 1) {
            return n - mod;
        } else {
            return 1 + mod;
        }
    }
}