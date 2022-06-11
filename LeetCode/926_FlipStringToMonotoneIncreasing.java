class Solution {
    public int minFlipsMonoIncr(String s) {
        int zero = 0, one = 0;
        for(char c : s.toCharArray()) {
            if(c == '0') {
                one = Math.min(zero, one) + 1;
            } else {
                one = Math.min(zero, one);
                zero++;
            } 
        }
        return Math.min(zero, one);
    }
}

// class Solution {
//     public int minFlipsMonoIncr(String s) {
//         int len = s.length();
//         int[][] dp = new int[len + 1][2];
//         for(int i = 1; i <= len; i++) {
//             if(s.charAt(i - 1) == '0') {
//                 dp[i][0] = dp[i - 1][0];
//                 dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][1]) + 1;
//             } else {
//                 dp[i][0] = dp[i - 1][0] + 1;
//                 dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][1]);
//             } 
//         }
//         return Math.min(dp[len][0], dp[len][1]);
//     }
// }