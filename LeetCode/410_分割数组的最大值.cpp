class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        // dp[i][j] 表示 nums[0...i] 被划分为 j 个子数组各自和的最大值最小
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, INT_MAX));
        vector<long long> subSum(n + 1, 0);
        for(int i = 0; i < n; i++) {
            subSum[i + 1] = subSum[i] + nums[i];
        }

        dp[0][0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                for(int k = 0; k < i; k++) {
                    dp[i][j] = min(dp[i][j], max(dp[k][j - 1], subSum[i] - subSum[k]));
                }
            }
        }

        return dp[n][m];
    }
};