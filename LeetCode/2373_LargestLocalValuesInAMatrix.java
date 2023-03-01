class Solution {
    public int[][] largestLocal(int[][] grid) {
        int n = grid.length;
        int[][] res = new int[n - 2][n - 2];

        for(int i = 0; i < n - 2; i++) {
            for(int j = 0; j < n - 2; j++) {
                for(int k = i; k < i + 3; k++) {
                    for(int l = j; l < j + 3; l++) {
                        res[i][j] = Math.max(res[i][j], grid[k][l]);
                    }
                }
            }
        }

        return res;
    }
}