class Solution {
    public int[][] transpose(int[][] A) {
        if(A.length == 0 || A[0].length == 0) {
            return A;
        }

        int row = A.length;
        int col = A[0].length;

        int[][] res = new int[col][row];
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                res[j][i] = A[i][j];
            }
        }

        return res;
    }
}