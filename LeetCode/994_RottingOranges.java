class Solution {
    private static final int[][] DIRECTIONS = new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    public int orangesRotting(int[][] grid) {
        int m = grid.length, n = grid[0].length, fresh = 0;
        List<int[]> q = new ArrayList<>();
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    q.add(new int[]{i, j});
                }
            }
        }

        int res = 0;
        while (fresh > 0 && !q.isEmpty()) {
            res++;
            List<int[]> temp = q;
            q = new ArrayList<>();
            for (int[] rotten : temp) {
                for (int[] d : DIRECTIONS) {
                    int i = rotten[0] + d[0], j = rotten[1] + d[1];
                    if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1) {
                        grid[i][j] = 2;
                        fresh--;
                        q.add(new int[]{i, j});
                    }
                }
            }
        }

        return fresh > 0 ? -1 : res;
    }
}