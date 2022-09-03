class Solution {
    public int findLongestChain(int[][] pairs) {
        Arrays.sort(pairs, (a, b) -> (a[1] - b[1]));
        int res = 1;
        int curRight = pairs[0][1];
        for(int i = 1; i < pairs.length; i++) {
            if(pairs[i][0] > curRight) {
                curRight = pairs[i][1];
                res++;
            }
        }

        return res;
    }
}