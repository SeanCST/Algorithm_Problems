class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        int[] coo1 = coordinates[0];
        int[] coo2 = coordinates[1];

        for(int i = 2; i < coordinates.length; i++) {
            int[] curCoo = coordinates[i];
            if((coo2[0] - coo1[0]) * (curCoo[1] - coo1[1]) != (coo2[1] - coo1[1]) * (curCoo[0] - coo1[0])) {
                return false;
            }
        }
        
        return true;
    }
}