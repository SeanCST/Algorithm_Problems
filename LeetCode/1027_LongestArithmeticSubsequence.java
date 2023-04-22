class Solution {
    public int longestArithSeqLength(int[] nums) {
        int n = nums.length;
        // f[i][j] 表示以 nums[i] 结尾且公差为 j 的等差子序列的最大长度。
        int[][] dp = new int[n][1001];

        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int d = nums[i] - nums[j] + 500;
                dp[i][d] = dp[j][d] + 1;
                res = Math.max(res, dp[i][d]);
            }
        }

        return res + 1;
    }
}