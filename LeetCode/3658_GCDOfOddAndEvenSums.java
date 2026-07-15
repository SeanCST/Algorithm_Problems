class Solution {
    public int gcdOfOddEvenSums(int n) {
        int sumOdd = (1 + 2 * n - 1) * n / 2;
        int sumEven = (2 + 2 * n) * n / 2;

        return GCD(sumEven, sumOdd);
    }

    private int GCD(int a, int b) {
        // return a % b == 0 ? b : GCD(a, a % b);
        return b == 0 ? a : GCD(b, a % b);
    }
}