class Solution {
    public int minElements(int[] nums, int limit, int goal) {
        double sum = 0;
        for(int num : nums) {
            sum += num;
        }
        double gap = Math.abs(goal - sum);

        return (int)Math.ceil(gap / limit);
    }
}