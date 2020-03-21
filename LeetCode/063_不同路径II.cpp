class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0) {
            return 0;
        }
        int n = obstacleGrid[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int count = 0;
                if(i == 0 && j == 0) {
                    dp[i][j] = obstacleGrid[i][j] == 0 ? 1 : 0;
                } else if (i == 0) {
                    dp[i][j] = dp[i][j - 1] && obstacleGrid[i][j] == 0 ? 1 : 0;
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] && obstacleGrid[i][j] == 0 ? 1 : 0;
                } else {
                    if(obstacleGrid[i][j] == 0) {
                        dp[i][j] += dp[i][j - 1] + dp[i - 1][j];
                    } else {
                        dp[i][j] = 0;
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};