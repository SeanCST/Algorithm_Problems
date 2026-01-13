class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int len1 = text1.length(), len2 = text2.length();
        int[][] dp = new int[2][len2 + 1];
        int k = 0;
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    dp[k][j] = dp[1 - k][j - 1] + 1;
                } else {
                    dp[k][j] = Math.max(dp[1 - k][j], dp[k][j - 1]);
                }
            }
            k = 1 - k;
        }

        // int[][] dp = new int[len1 + 1][len2 + 1];
        // for (int i = 1; i <= len1; i++) {
        //     for (int j = 1; j <= len2; j++) {
        //         if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
        //             dp[i][j] = dp[i - 1][j - 1] + 1;
        //         } else {
        //             dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
        //         }
        //     }
        // }

        return dp[1 - k][len2];
    }
}