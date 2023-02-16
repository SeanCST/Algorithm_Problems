class Solution {
    public int[] numberOfPairs(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int removed = 0, i = 0;
        while(i < n) {
            if(i < n - 1 && nums[i] == nums[i + 1]) {
                removed += 1;
                i += 2;
            } else {
                i++;
            }
        }

        return new int[]{removed, n - removed * 2};
    }
}