class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) {
            return true;
        }
        int n = matrix[0].size();

        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(r + 1 < m && c + 1 < n && matrix[r][c] != matrix[r + 1][c + 1]) {
                    return false;
                }
            }
        }

        return true;
    }
};

// class Solution {
// public:
//     bool isToeplitzMatrix(vector<vector<int>>& matrix) {
//         int row = matrix.size();
//         if(row == 0) return false;
//         int column = matrix[0].size();
//         if(column == 0) return false;

//         for(int r = 0; r < row; r++) {
//             for(int c = 0; c < column; c++) {
//                 if(r + 1 < row && c + 1 < column) {
//                     if(matrix[r][c] != matrix[r + 1][c + 1]) {
//                         return false;
//                     }
//                 }
//             }
//         }

//         return true;
//     }
// };

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row == 0) return false;
        int column = matrix[0].size();
        if(column == 0) return false;

        // 一条对角线上的各数的 r - c 值相同
        map<int, int> groups;
        for(int r = 0; r < row; r++) {
            for(int c = 0; c < column; c++) {
                if(groups.count(r - c) == 0) {
                    groups[r - c] = matrix[r][c];
                } else if(groups[r - c] != matrix[r][c]) {
                    return false;
                }
            }
        }

        return true;
    }
};

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) {
            return true;
        }
        int n = matrix[0].size();

        for(int row = m - 1; row >= 0; row--) {
            int r = row, c = 0;
            int num = matrix[r][c];
            while(r < m && c < n) {
                if(matrix[r][c] != num) {
                    return false;
                }
                r++;
                c++;
            }
        }

        for(int col = 1; col < n; col++) {
            int r = 0, c = col;
            int num = matrix[r][c];
            while(r < m && c < n) {
                if(matrix[r][c] != num) {
                    return false;
                }
                r++;
                c++;
            }
        }

        return true;
    }
};