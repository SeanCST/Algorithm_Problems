class Solution {
    public int maxProduct(int[] nums) {
        int max = nums[0], min = nums[0], ans = nums[0];

        for (int i = 1; i < nums.length; i++) {
            int cur = nums[i];
            int tempMax = max;
            max = Math.max(cur, Math.max(max * cur, min * cur));
            min = Math.min(cur, Math.min(tempMax * cur, min * cur));

            ans = Math.max(ans, max);
        }

        return ans;
    }
}