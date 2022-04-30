class Solution {
    public int smallestRangeI(int[] nums, int k) {
/*      
        int max = 0, min = 10000;
        for (int num : nums) {
            if(num > max) {
                max = num;
            }
            if(num < min) {
                min = num;
            }
        }
*/        

        Arrays.sort(nums);
        int difference = nums[nums.length -1] - nums[0];
        
        if(difference <= k * 2) {
            return 0;
        } else {
            return difference - k * 2;
        }
    }
}