class Solution {
    public int findUnsortedSubarray(int[] nums) {

        int leftMax = nums[0];
        int lastModifyIndex = -1;
        for(int i = 1; i < nums.length; i++) {
            if (nums[i] < leftMax) {
                lastModifyIndex = i;
            } else {
                leftMax = nums[i];
            }
        }

        int rightMin = nums[nums.length - 1];
        int firstModifyIndex = -1;
        for(int i = nums.length - 2; i >= 0; i--) {
            if (nums[i] > rightMin) {
                firstModifyIndex = i;
            } else {
                rightMin = nums[i];
            }
        }

        return firstModifyIndex == lastModifyIndex ? 0 : lastModifyIndex - firstModifyIndex + 1;
    }
}