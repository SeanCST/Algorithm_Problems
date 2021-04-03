class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length();
        int n = text2.length();

        // char[][] direction = new char[m + 1][n + 1];
        int[][] length = new int[m + 1][n + 1];

        for(int i = 0; i <= m; i++) {
            length[i][0] = 0;
        }
        for(int j = 0; j <= n; j++) {
            length[0][j] = 0;
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    // direction[i][j] = '1'; // 斜上方
                    length[i][j] = length[i - 1][j - 1] + 1;
                } else if(length[i - 1][j] >= length[i][j - 1]) {
                    // direction[i][j] = '2'; // 上方
                    length[i][j] = length[i - 1][j];
                } else {
                    // direction[i][j] = '3'; // 左方
                    length[i][j] = length[i][j - 1];
                }
            }
        }

        // int r = m, c = n;
        // StringBuilder sb = new StringBuilder();
        // while(r > 0 && c > 0) {
        //     if(direction[r][c] == '1') {
        //         sb.insert(0, text1.charAt(r - 1));
        //         r--;
        //         c--;
        //     } else if(direction[r][c] == '2') {
        //         r--;
        //     } else {
        //         c--;
        //     }
        // }

        return length[m][n];
    }
}