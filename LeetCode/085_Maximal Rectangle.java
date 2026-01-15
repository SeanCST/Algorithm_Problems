class Solution {
    public int maximalRectangle(char[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int[] heights = new int[n + 1];
        int res = 0;

        for (char[] row : matrix) {
            for (int i = 0; i < n; i++) {
                if (row[i] == '1') {
                    heights[i]++;
                } else {
                    heights[i] = 0;
                }
            }
            res = Math.max(res, maxArea(heights));
        }

        return res;
    }

    private int maxArea(int[] heights) {
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(-1);
        int maxArea = 0;
        for (int right = 0; right < heights.length; right++) {
            while (stack.peek() != -1 && heights[stack.peek()] >= heights[right]) {
                int h = heights[stack.peek()];
                stack.pop();
                int left = stack.peek();
                maxArea = Math.max(maxArea, h * (right - left - 1));
            }

            stack.push(right);
        }

        return maxArea;
    }
}