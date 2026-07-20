class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int m = grid.length, n = grid[0].length;
        List<List<Integer>> ans = new ArrayList<>(m);
        for(int i = 0; i < m; i++) {
            List<Integer> row = new ArrayList<>(Collections.nCopies(n, 0));
            ans.add(row);
        }

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                // int nr = (r + (c + k) / n) % m;
                // int nc = (c + k) % n;
                // ans.get(nr).set(nc, grid[r][c]);

                int index = (r * n + c + k) % (m * n);
                ans.get(index / n).set(index % n, grid[r][c]);
            }
        }

        return ans;
    }
}