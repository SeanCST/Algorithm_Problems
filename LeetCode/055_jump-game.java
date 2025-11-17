class Solution {
    public boolean canJump(int[] nums) {
        int maxPosition = 0;
        int len = nums.length;
        for (int i = 0; i < len; i++) {
            if (i <= maxPosition) {
                maxPosition = Math.max(i + nums[i], maxPosition);
                if(maxPosition >= len - 1) {
                    return true;
                }
            }
        }

        return false;
    }
}