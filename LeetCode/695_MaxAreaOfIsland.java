class Solution {
    private static final int[][] DIRECTIONS = new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    public int maxAreaOfIsland(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int ans = 0;
        boolean[][] visited = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    ans = Math.max(ans, getArea(grid, visited, i, j, m, n));
                }
            }
        }

        return ans;
    }

    private int getArea(int[][] grid, boolean[][] visited, int i, int j, int m, int n) {
        Deque<int[]> queue = new ArrayDeque<>();
        queue.offer(new int[]{i, j});
        visited[i][j] = true;
        int area = 0;
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            area++;
            
            for (int[] d : DIRECTIONS) {
                int x = cur[0] + d[0], y = cur[1] + d[1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 && !visited[x][y]) {
                    queue.offer(new int[]{x, y});
                    visited[x][y] = true;
                }
            }
        }

        return area;
    }
}