class Solution {
    public int jump(int[] nums) {
        int len = nums.length;
        int maxPosition = 0;
        int end = 0;
        int steps = 0;

        for (int i = 0; i < len - 1; i++) {
            maxPosition = Math.max(maxPosition, nums[i] + i);
            if (i == end) {
                end = maxPosition;
                steps++;
            }
        }

        return steps;
    }
}

class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j <= i + nums[i] && j < n; j++) {
                dp[j] = Math.min(dp[j], dp[i] + 1);
            }
        }

        return dp[n - 1];
    }
}