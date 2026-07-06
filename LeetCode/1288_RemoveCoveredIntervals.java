class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[0] != b[0] ? a[0] - b[0] : b[1] - a[1]);

        int ans = 0, maxR = 0;
        for (int[] interval : intervals) {
            if(interval[1] > maxR) {
                maxR = interval[1];
                ans++;
            }
        }

        return ans;
    }
}