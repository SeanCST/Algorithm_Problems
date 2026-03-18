class Solution {
    public int maxSubArray(int[] nums) {
        int pre = 0, ans = Integer.MIN_VALUE;

        for (int num : nums) {
            pre = Math.max(pre + num, num);
            ans = Math.max(ans, pre);
        }

        return ans;
    }
}