class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        if(row == 0) {
            return 0;
        }
        int col = grid[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0)); // 初始化二维数组
        int maxArea = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 1 && visited[i][j] == 0) {
                    int curCount = count(grid, visited, i, j, row, col);
                    maxArea = max(maxArea, curCount);
                }
            }
        }

        return maxArea;
    }

    int count(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j, int row, int col) {
        if(i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 0 || visited[i][j] == 1) {
            return 0;
        }
        int curCount = 1;
        visited[i][j] = 1;
        curCount += count(grid, visited, i - 1, j, row, col);
        curCount += count(grid, visited, i + 1, j, row, col);
        curCount += count(grid, visited, i, j - 1, row, col);
        curCount += count(grid, visited, i, j + 1, row, col);

        return curCount;
    }
};