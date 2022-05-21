class Solution {
    public int repeatedNTimes(int[] nums) {
        if(nums[1] == nums[3]) {
            return nums[1];
        }

        for(int i = 0; i < nums.length - 1; i ++) {
            if(nums[i] == nums[i + 1]) {
                return nums[i];
            }
        }

        return nums[0];
    }
}