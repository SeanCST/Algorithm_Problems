class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] buckets = new int[26];
        for (char task : tasks) {
            buckets[task - 'A']++;
        }
        Arrays.sort(buckets);
        int maxTimes = buckets[25], maxCount = 1;

        for (int i = 25; i >= 1; i--) {
            if (buckets[i] == buckets[i - 1]) {
                maxCount++;
            } else {
                break;
            }
        }

        return Math.max((maxTimes - 1) * (n + 1) + maxCount, tasks.length);
    }
}