class Solution {
    private static int[][] DIRS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    public boolean findSafeWalk(List<List<Integer>> grid, int health) {
        int m = grid.size(), n = grid.get(0).size();
        int[][] dis = new int[m][n];
        for (int i = 0; i < m; i++) {
            Arrays.fill(dis[i], -1);
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        pq.offer(new int[]{grid.get(0).get(0), 0, 0});

        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int val = cur[0], cx = cur[1], cy = cur[2];
            if(dis[cx][cy] >= 0) {
                continue;
            }

            dis[cx][cy] = val;
            for (int[] dir : DIRS) {
                int nx = cx + dir[0], ny = cy + dir[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || dis[nx][ny] >= 0) {
                    continue;
                }
                pq.offer(new int[]{val + grid.get(nx).get(ny), nx, ny});
            }
        }

        return dis[m - 1][n - 1] < health;
    }
}