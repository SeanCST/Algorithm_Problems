class Solution {
    public int trap(int[] height) {
        int n = height.length;
        if (n <= 2) {
            return 0;
        }

        int[] left = new int[n];
        int[] right = new int[n];

        for (int i = 1; i < n; i++) {
            left[i] = Math.max(left[i - 1], height[i - 1]);
        }

        for (int i = n - 2; i >= 0; i--) {
            right[i] = Math.max(right[i + 1], height[i + 1]);
        }

        int res = 0;
        for (int i = 1; i < n - 1; i++) {
            res += Math.max(0, Math.min(left[i], right[i]) - height[i]);
        }

        return res;
    }
}