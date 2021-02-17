class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        if(nums.length == 0 || nums[0].length == 0) {
            return nums;
        }
        int row = nums.length;
        int col = nums[0].length;
        if(row * col != r * c) {
            return nums;
        }

        int[][] res = new int[r][c];
        int k = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                res[i][j] = nums[k / col][k % col];
                k++;
            }
        }

        return res;
    }
}