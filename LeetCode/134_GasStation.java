class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        int curSum = 0, totalSum = 0, res = 0;
        for (int i = 0; i < n; i++) {
            int cur = gas[i] - cost[i];
            curSum += cur;
            totalSum += cur;
            if (curSum < 0) {
                res = i + 1;
                curSum = 0;
            }
        }

        return totalSum < 0 ? -1 : res;
    }
}