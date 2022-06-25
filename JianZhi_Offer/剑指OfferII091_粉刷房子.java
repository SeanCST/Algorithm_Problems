class Solution {
    public int minCost(int[][] costs) {
        int n = costs.length;

        int[][] painting = new int[n][3];
        for(int j = 0; j < 3; j++) {
            painting[0][j] = costs[0][j];
        }

        for(int i = 1; i < n; i++) {
            painting[i][0] = Math.min(painting[i - 1][1], painting[i - 1][2]) + costs[i][0];
            painting[i][1] = Math.min(painting[i - 1][0], painting[i - 1][2]) + costs[i][1];
            painting[i][2] = Math.min(painting[i - 1][0], painting[i - 1][1]) + costs[i][2];
        }

        return Math.min(painting[n - 1][0], Math.min(painting[n - 1][1], painting[n - 1][2]));
    }
}