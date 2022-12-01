class Solution {
    public int nearestValidPoint(int x, int y, int[][] points) {
        int res = -1;
        int minManhattanDistance = Integer.MAX_VALUE;
        for(int i = 0; i < points.length; i++) {
            int[] point = points[i];
            if(point[0] == x || point[1] == y) {
                int manhattanDistance = Math.abs(point[0] - x) + Math.abs(point[1] - y);
                if(manhattanDistance < minManhattanDistance) {
                    res = i;
                    minManhattanDistance = manhattanDistance;
                }
            }
        }

        return res;
    }
}