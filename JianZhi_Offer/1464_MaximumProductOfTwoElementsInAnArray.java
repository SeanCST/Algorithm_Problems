class Solution {
    public int maxProduct(int[] nums) {
        int maxIndex = 0, secondMaxIndex = 0;
        if(nums[0] < nums[1]) {
            maxIndex = 1;
        } else {
            secondMaxIndex = 1;
        }

        for(int i = 2; i < nums.length; i++) {
            if(nums[i] >= nums[maxIndex]) {
                secondMaxIndex = maxIndex;
                maxIndex = i;
            } else if (nums[i] > nums[secondMaxIndex]) {
                secondMaxIndex = i;
            }
        }

        return (nums[maxIndex] - 1) * (nums[secondMaxIndex] - 1);
    }
}