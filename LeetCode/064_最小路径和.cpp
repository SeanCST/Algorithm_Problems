class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m == 0 || n == 0) {
            return 0;
        }
        vector<int> dp(n, 0);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(j == 0) { // 只能从上侧走到该位置
                    dp[j] = dp[j];
                } else if(i == 0) { // 只能从左侧走到该位置
                    dp[j] = dp[j - 1];
                } else {
                    dp[j] = min(dp[j], dp[j - 1]);
                }

                dp[j] += grid[i][j];
            }
        }

        return dp[n - 1];
    }
};