class Solution {
    private int[] rows = new int[9];
    private int[] cols = new int[9];
    private int[] boxes = new int[9];

    public void solveSudoku(char[][] board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    int num = board[r][c] - '1';
                    int mask = 1 << num;
                    rows[r] |= mask;
                    cols[c] |= mask;
                    boxes[boxId(r, c)] |= mask;
                }
            }
        }

        backtrace(board, 0, 0);
    }

    private int boxId(int r, int c) {
        return (r / 3) * 3 + c / 3;
    }

    private boolean backtrace(char[][] board, int r, int c) {
        if (r == 9) {
            return true;
        }
        if (c == 9) {
            return backtrace(board, r + 1, 0);
        }
        if (board[r][c] != '.') {
            return backtrace(board, r, c + 1);
        }

        int box = boxId(r, c);
        int used = rows[r] | cols[c] | boxes[box];
        for (int d = 0; d < 9; d++) {
            int mask = 1 << d;
            if ((used & mask) != 0) {
                continue;
            }
            board[r][c] = (char)('1' + d);
            rows[r] |= mask;
            cols[c] |= mask;
            boxes[box] |= mask;

            if (backtrace(board, r, c + 1)) {
                return true;
            }

            rows[r] ^= mask;
            cols[c] ^= mask;
            boxes[box] ^= mask;
            board[r][c] = '.';
        }

        return false;
    }
}

// class Solution {
//     public void solveSudoku(char[][] board) {
//         backtrace(board);
//     }

//     private boolean backtrace(char[][] board) {
//         for (int i = 0; i < 9; i++) {
//             for (int j = 0; j < 9; j++) {
//                 if (board[i][j] != '.') {
//                     continue;
//                 }

//                 for (char c = '1'; c <= '9'; c++) {
//                     if (isValid(board, i, j, c)) {
//                         board[i][j] = c;
//                         if (backtrace(board)) {
//                             return true;
//                         }
//                         board[i][j] = '.';
//                     }
//                 }
//                 return false;
//             }
//         }
//         return true;
//     }

//     private boolean isValid(char[][] board, int row, int col, char c) {
//         for (int k = 0; k < 9; k++) {
//             if (board[row][k] == c || board[k][col] == c) {
//                 return false;
//             }

//             int br = (row / 3) * 3 + k / 3;
//             int bc = (col / 3) * 3 + k % 3;
//             if (board[br][bc] == c) {
//                 return false;
//             }
//         }

//         return true;
//     }
// }