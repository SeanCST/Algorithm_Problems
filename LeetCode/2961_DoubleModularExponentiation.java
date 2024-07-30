class Solution {
    public List<Integer> getGoodIndices(int[][] variables, int target) {
        List<Integer> goodIndices = new ArrayList<>();
        for(int i = 0; i < variables.length; i++) {
            int[] variable = variables[i];
            if(powerMod(powerMod(variable[0], variable[1], 10), variable[2], variable[3]) == target) {
                goodIndices.add(i);
            }
        }

        return goodIndices;
    }

    private int powerMod(int a, int b, int c) {
        if(b == 1) {
            return a % c;
        }
        if(b % 2 == 0) {
            int x = powerMod(a, b / 2, c);
            return x * x % c;
        } else {
            return powerMod(a, b - 1, c) * powerMod (a, 1, c) % c;
        }
    }
}