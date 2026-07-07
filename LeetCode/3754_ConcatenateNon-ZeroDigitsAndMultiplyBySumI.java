class Solution {
    public long sumAndMultiply(int n) {
        long sum = 0, x = 0, k = 1;
        while (n > 0) {
            int cur = n % 10;
            if (cur != 0) {
                sum += cur;
                x = cur * k + x;
                k *= 10;
            }
            n /= 10;
        }

        return x * sum;
    }
}