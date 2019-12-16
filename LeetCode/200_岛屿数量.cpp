class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row == 0) {
            return 0;
        }
        int col = grid[0].size();
        int num = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(isIsland(grid, row, col, i, j)) {
                    num++;
                }
            }
        }

        return num;
    }

    bool isIsland(vector<vector<char>>& grid, int row, int col, int i, int j) {
        if(i >= row || i < 0 || j >= col || j < 0 || grid[i][j] == '0') {
            return false;
        }
        grid[i][j] = '0';
        bool cur = true;
        cur = isIsland(grid, row, col, i + 1, j) || cur;
        cur = isIsland(grid, row, col, i - 1, j) || cur;
        cur = isIsland(grid, row, col, i, j + 1) || cur;
        cur = isIsland(grid, row, col, i, j - 1) || cur;
        
        return cur;
    }
};