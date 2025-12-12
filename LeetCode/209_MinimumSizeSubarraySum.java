class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int res = Integer.MAX_VALUE;

        int l = 0, sum = 0;
        for (int r = 0; r < nums.length; r++) {
            sum += nums[r];
            while (sum >= target) {
                res = Math.min(res, r - l + 1);
                sum -= nums[l++];
            }
        }

        return res == Integer.MAX_VALUE ? 0 : res;
    }
}