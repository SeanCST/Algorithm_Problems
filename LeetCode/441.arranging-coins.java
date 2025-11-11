class Solution {
    public int arrangeCoins(int n) {
        int l = 1, r = n;
        while(l < r) {
            int mid = l + (r - l + 1) / 2;
            if ((long) mid * (1 + mid) <= (long) 2 * n) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        return l;
    }
}