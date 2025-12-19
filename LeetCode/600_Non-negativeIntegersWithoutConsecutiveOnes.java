class Solution {
    public int findIntegers(int n) {
        int[] dp = new int[31];
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < 31; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        int preBit = 0, res =0;
        for (int i = 30; i >= 0; i--) {
            if ((n & (1 << i)) != 0) {
                res += dp[i];
                if (preBit == 1) {
                    return res;
                }
                preBit = 1;
            } else {
                preBit = 0;
            }
        } 

        return res + 1;
    }
}