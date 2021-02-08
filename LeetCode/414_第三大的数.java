class Solution {
    public int thirdMax(int[] nums) {
        long firstMax = Long.MIN_VALUE, secondMax = Long.MIN_VALUE, thirdMax = Long.MIN_VALUE;

        for(int i = 0; i < nums.length; i++) {
            if(firstMax < nums[i]) {
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = nums[i];
            } else if(firstMax > nums[i] && secondMax < nums[i]) {
                thirdMax = secondMax;
                secondMax = nums[i];
            } else if(secondMax > nums[i] && thirdMax < nums[i]) {
                thirdMax = nums[i];
            }
        }

        int res;
        if(thirdMax > Long.MIN_VALUE) {
            res = (int)thirdMax;
        } else {
            res = (int)firstMax;
        }

        return res;
    }
}