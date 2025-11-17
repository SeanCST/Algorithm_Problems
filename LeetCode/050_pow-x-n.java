class Solution {
    public double myPow(double x, int n) {
        long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }

    private double quickMul(double x, long N) {
        double res = 1.0;
        double x_contribute = x;
        while (N > 0) {
            if (N % 2 == 1) {
                res *= x_contribute;
            }
            x_contribute *= x_contribute;
            N /= 2;
        }

        return res;
    }

    // private double quickMul(double x, long n) {
    //     if (n == 0) {
    //         return 1.0;
    //     }

    //     double temp = quickMul(x, n / 2);
    //     return n % 2 == 0 ? temp * temp : temp * temp * x;
    // }
}