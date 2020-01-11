class Solution {
private:
    int n = 3;
    int N = 9;
    bool sudokuSolved = false;
    vector<vector<bool>> rowUsed;
    vector<vector<bool>> colUsed;
    vector<vector<bool>> cubeUsed;
    vector<vector<char>> bb;
    
public:
    Solution() {
        rowUsed.resize(N, vector<bool>(N + 1, false));
        colUsed.resize(N, vector<bool>(N + 1, false));
        cubeUsed.resize(N, vector<bool>(N + 1, false));
    }
    
    bool couldPlace(int d, int row, int col) {
        int idx = (row / n) * n + col / n; // 标志着第几个 cube
        return rowUsed[row][d] == false && colUsed[col][d] == false && cubeUsed[idx][d] == false;
    }
    
    void placeNumber(int d, int row, int col) {
        int idx = (row / n) * n + col / n;
        bb[row][col] = '0' + d;
        rowUsed[row][d] = true;
        colUsed[col][d] = true;
        cubeUsed[idx][d] = true;
    }
    
    void placeNextNumber(int row, int col) {
        if(col == N - 1 && row == N - 1) {
            sudokuSolved = true;
        } else {
            if(col == N - 1) {
                backtracing(row + 1, 0);
            } else {
                backtracing(row, col + 1);
            }
        }
        
    }
    
    void removeNumber(int d, int row, int col) {
        int idx = (row / n) * n + col / n;
        bb[row][col] = '.';
        rowUsed[row][d] = false;
        colUsed[col][d] = false;
        cubeUsed[idx][d] = false;
    }
    
    void backtracing(int row, int col) {
        if(bb[row][col] == '.') {
            for(int d = 1; d <= 9; d++) {
                if(couldPlace(d, row, col)) {
                    placeNumber(d, row, col);
                    placeNextNumber(row, col);
                    if(!sudokuSolved) { // 回溯
                        removeNumber(d, row, col);
                    }
                }
            }
        } else {
            placeNextNumber(row, col);
        }
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        bb = board;
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(bb[i][j] != '.') {
                    placeNumber(bb[i][j] - '0', i, j);
                }
            }
        }
        
        backtracing(0, 0);
        
        board = bb;
    }
};