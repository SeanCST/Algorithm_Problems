class Solution {
    public int numIslands(char[][] grid) {
        int m = grid.length, n = grid[0].length;
        boolean[][] visited = new boolean[m][n];
        int res = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, i, j, m, n, visited);
                    res++;
                }
            }
        }

        return res;
    }

    void dfs(char[][] grid, int i, int j, int m, int n, boolean[][] visited) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0' || visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        dfs(grid, i + 1, j, m, n, visited);
        dfs(grid, i - 1, j, m, n, visited);
        dfs(grid, i, j + 1, m, n, visited);
        dfs(grid, i, j - 1, m, n, visited);
    }
}

class Solution {
    private static final int[][] DIRECTIONS = new int[][]{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    public int numIslands(char[][] grid) {
        int m = grid.length, n = grid[0].length;
        boolean[][] visited = new boolean[m][n];
        
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {   
                    Deque<int[]> queue = new ArrayDeque<>();
                    queue.offer(new int[]{i, j});
                    visited[i][j] = true;
                    while (!queue.isEmpty()) {
                        int[] pos = queue.poll();
                        for (int[] d : DIRECTIONS) {
                            int x = pos[0] + d[0];
                            int y = pos[1] + d[1];
                            if (x >= 0 && x < m && y >=0 && y < n && grid[x][y] == '1' && !visited[x][y]) {
                                queue.offer(new int[]{x, y});
                                visited[x][y] = true;
                            }
                        }
                    }
                    res++;
                }
            }
        }

        return res;
    }

}