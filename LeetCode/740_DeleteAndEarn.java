class Solution {
    public int deleteAndEarn(int[] nums) {
        int max = 0;
        for (int num : nums) {
            max = Math.max(max, num);
        }

        int[] a = new int[max + 1];
        for (int num : nums) {
            a[num] += num;
        }

        return rob(a);
    }

    private int rob(int[] nums) {
        int n = nums.length;
        // int[] dp = new int[n + 2];
        int f0 = 0, f1 = 0;
        for (int i = 0; i < n; i++) {
            // dp[i + 2] = Math.max(dp[i + 1], dp[i] + nums[i]);
            int cur = Math.max(f1, f0 + nums[i]);
            f0 = f1;
            f1 = cur;
        }

        // return dp[n + 1];
        return f1;
    }
}