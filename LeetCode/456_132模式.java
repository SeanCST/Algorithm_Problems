class Solution {
    public boolean find132pattern(int[] nums) {
        Stack<Integer> stk = new Stack<>(); // 单调栈，存储 3
        Integer last = Integer.MIN_VALUE; // 存储 2

        for (int i = nums.length - 1; i >= 0; i--) {
            if (nums[i] < last) { // 遇到 1
                return true;
            }

            while (!stk.isEmpty() && nums[i] > stk.peek()) {
                last = stk.pop();
            }
            
            stk.push(nums[i]);
        }

        return false;
    }
}