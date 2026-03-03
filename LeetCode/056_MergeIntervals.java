class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (int[] a, int[] b) -> Integer.compare(a[0], b[0]));

        List<int[]> ans = new ArrayList<>();
        int l = intervals[0][0], r = intervals[0][1];

        for (int i = 1; i < intervals.length; i++) {
            int[] interval = intervals[i];
            if (interval[0] > r) {
                ans.add(new int[]{l, r});
                l = interval[0];
                r = interval[1];
            } else {
                r = Math.max(r, interval[1]);
            }
        }

        ans.add(new int[]{l, r});

        return ans.toArray(new int[ans.size()][]);
    }
}