class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length, sum = 0;
        for (int num : nums) {
            sum += num;
        }

        return (1 + n) * n / 2 - sum;
    }
}