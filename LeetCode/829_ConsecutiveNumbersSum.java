class Solution {
    public int consecutiveNumbersSum(int n) {
        int res = 0;
        n *= 2;
        for(int k = 1; k * k < n; k++) {
            if(n % k != 0) {
                continue;
            }
            if((n / k - k + 1) % 2 == 0) {
                res++;
            }
        }

        return res;
    }
}