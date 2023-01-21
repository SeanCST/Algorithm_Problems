class Solution {
    static final int INF = Integer.MAX_VALUE;

    public int minSideJumps(int[] obstacles) {
        int n = obstacles.length;
        int[][] dp = new int[n][3];

        dp[0][1] = 0;
        dp[0][0] = 1;
        dp[0][2] = 1;

        for(int i = 1; i < n; i++) {
            int minCnt = INF;

            for(int j = 0; j < 3; j++) {
                if(obstacles[i] - 1 == j) {
                    dp[i][j] = INF;
                } else {
                    minCnt = Math.min(minCnt, dp[i - 1][j]);
                }
            }

            for(int j = 0; j < 3; j++) {
                if(obstacles[i] - 1 == j) {
                    continue;
                } else {
                    dp[i][j] = Math.min(minCnt + 1, dp[i - 1][j]);
                }
            }
        }
        
        return Math.min(dp[n - 1][0], Math.min(dp[n - 1][1], dp[n - 1][2]));
    }
}