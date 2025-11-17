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