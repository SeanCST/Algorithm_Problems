class Solution {
    private static final int[][] DIRS = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    public int maximumSafenessFactor(List<List<Integer>> grid) {
        int n = grid.size();

        // 1. 多源 BFS：计算每个格子到最近小偷的距离
        int[][] dist = new int[n][n];
        for (int[] row : dist) {
            Arrays.fill(row, -1);
        }

        Queue<int[]> queue = new ArrayDeque<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid.get(i).get(j) == 1) {
                    dist[i][j] = 0;
                    queue.offer(new int[]{i, j});
                }
            }
        }

        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int x = cur[0];
            int y = cur[1];

            for (int[] dir : DIRS) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n || dist[nx][ny] != -1) {
                    continue;
                }

                dist[nx][ny] = dist[x][y] + 1;
                queue.offer(new int[]{nx, ny});
            }
        }

        // 2. 二分答案
        int left = 0;
        int right = Math.min(dist[0][0], dist[n - 1][n - 1]);
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canReach(dist, mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }

    // 判断是否存在一条路径，使得路径上所有格子的 dist 都 >= limit
    private boolean canReach(int[][] dist, int limit) {
        int n = dist.length;

        if (dist[0][0] < limit || dist[n - 1][n - 1] < limit) {
            return false;
        }

        boolean[][] visited = new boolean[n][n];
        Queue<int[]> queue = new ArrayDeque<>();

        visited[0][0] = true;
        queue.offer(new int[]{0, 0});

        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int x = cur[0];
            int y = cur[1];

            if (x == n - 1 && y == n - 1) {
                return true;
            }

            for (int[] dir : DIRS) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] || dist[nx][ny] < limit) {
                    continue;
                }

                visited[nx][ny] = true;
                queue.offer(new int[]{nx, ny});
            }
        }

        return false;
    }
}