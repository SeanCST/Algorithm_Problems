class Solution {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length, res = 0;
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(-1);

        for (int right = 0; right <= n; right++) {
            int rightHeight = right < n ? heights[right] : 0;
            while (stack.peek() != -1 && heights[stack.peek()] >= rightHeight) {
                int h = heights[stack.pop()];
                int left = stack.peek();
                res = Math.max(res, h * (right - left - 1));
            }

            stack.push(right);
        }

        return res;
    }
}