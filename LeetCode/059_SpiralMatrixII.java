class Solution {
    public int[][] generateMatrix(int n) {
        int left = -1, right = n - 1, top = 0, bottom = n - 1;
        int cur = 1;
        int[][] res = new int[n][n];
        while (cur <= n * n) {
            for (int i = ++left; i <= right; i++) {
                res[top][i] = cur++;
            }
            for (int i = ++top; i <= bottom; i++) {
                res[i][right] = cur++;
            }
            for (int i = --right; i >= left; i--) {
                res[bottom][i] = cur++;
            }
            for (int i = --bottom; i >= top; i--) {
                res[i][left] = cur++;
            }
        }

        return res;
    }
}