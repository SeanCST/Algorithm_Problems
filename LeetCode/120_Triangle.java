class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[] dp = new int[n + 1];

        for (int i = n - 1; i >= 0; i--) {
            List<Integer> row = triangle.get(i);
            for (int j = 0; j < row.size(); j++) {
                dp[j] = row.get(j) + Math.min(dp[j + 1], dp[j]);
            }
        }

        return dp[0];
    }
}

// class Solution {
//     public int minimumTotal(List<List<Integer>> triangle) {
//         int n = triangle.size();
//         int[][] dp = new int[n + 1][n];
//         dp[1][0] = triangle.get(0).get(0);

//         for (int i = 2; i <= n; i++) {
//             List<Integer> row = triangle.get(i - 1);
//             for (int j = 0; j < row.size(); j++) {
//                 if (j == 0) {
//                     dp[i][j] = row.get(j) + dp[i - 1][j];
//                 } else if (j == row.size() - 1) {
//                     dp[i][j] = row.get(j) + dp[i - 1][j - 1];
//                 } else {
//                     dp[i][j] = row.get(j) + Math.min(dp[i - 1][j], dp[i - 1][j - 1]);
//                 }
//             }
//         }

//         int res = Integer.MAX_VALUE;
//         for (int i = 0; i < n; i++) {
//             res = Math.min(res, dp[n][i]);
//         }

//         return res;
//     }
// }