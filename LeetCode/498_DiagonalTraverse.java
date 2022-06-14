class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        int[] res = new int[m * n];
        int k = 0, i = 0, j = 0;
        while(k < m * n) {
            // direction: up right
            while(i >= 0 && j < n) {
                res[k++] = mat[i--][j++];
            }
            if(j >= n) {
                i += 2;
                j--;
            }  else if(i < 0) {
                i++;
            }

            // direction: down left
            while(i < m && j >= 0) {
                res[k++] = mat[i++][j--];
            }
            if(i >= m) {
                i--;
                j += 2;
            } else if(j < 0) {
                j++;
            }
        }

        return res;
    }
}