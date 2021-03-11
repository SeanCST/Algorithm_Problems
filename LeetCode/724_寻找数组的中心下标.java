class Solution {
    public int pivotIndex(int[] nums) {
        int sum = 0;
        for(int num : nums) {
            sum += num;
        }

        int curSum = 0;
        for(int i = 0; i < nums.length; i++) {
            int rightSum = sum - nums[i] - curSum;
            if(curSum == rightSum) {
                return i;
            }
            curSum += nums[i];
        }

        return -1;
    }
}