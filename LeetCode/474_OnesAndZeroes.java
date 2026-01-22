class Solution {
    
    public int findMaxForm(String[] strs, int m, int n) {
        int len = strs.length;
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 0; i < len; i++) {
            int[] zerosOnes = getZerosOnes(strs[i]);
            int zeroCnt = zerosOnes[0], oneCnt = zerosOnes[1];
            for (int j = m; j >= 0; j--) {
                for (int k = n; k >= 0; k--) {
                    if (j >= zeroCnt && k >= oneCnt) {
                        dp[j][k] = Math.max(dp[j][k], dp[j - zeroCnt][k - oneCnt] + 1);
                    }
                }
            }
        }

        return dp[m][n];
    }

    // public int findMaxForm(String[] strs, int m, int n) {
    //     int len = strs.length;
    //     int[][][] dp = new int[len + 1][m + 1][n + 1];
    //     for (int i = 1; i <= len; i++) {
    //         int[] zerosOnes = getZerosOnes(strs[i - 1]);
    //         int zeroCnt = zerosOnes[0], oneCnt = zerosOnes[1];
    //         for (int j = 0; j <= m; j++) {
    //             for (int k = 0; k <= n; k++) {
    //                 dp[i][j][k] = dp[i - 1][j][k];
    //                 if (j >= zeroCnt && k >= oneCnt) {
    //                     dp[i][j][k] = Math.max(dp[i][j][k], dp[i - 1][j - zeroCnt][k - oneCnt] + 1);
    //                 }
    //             }
    //         }
    //     }

    //     return dp[len][m][n];
    // }

    private int[] getZerosOnes(String str) {
        int[] zerosOnes = new int[2];
        for (char c : str.toCharArray()) {
            zerosOnes[c - '0']++;
        }
        return zerosOnes;
    }
}