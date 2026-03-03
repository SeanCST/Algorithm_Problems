class Solution {
    public int mySqrt(int x) {
        if (x <= 1) {
            return x;
        }

        int l = 1, r = x / 2;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int temp = x / mid;
            if (temp == mid) {
                return mid;
            } else if (temp > mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return r;
    }
}