class Solution {
    public int maximumGap(int[] nums) {
        int n = nums.length, min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            min = Math.min(nums[i], min);
            max = Math.max(nums[i], max);
        }
        if (n <= 1 || min == max) {
            return 0;
        }

        int bucketSize = Math.max(1, (max - min) / (n - 1));
        int bucketCount = (max - min) / bucketSize + 1;

        int[] bucketMin = new int[bucketCount];
        int[] bucketMax = new int[bucketCount];
        Arrays.fill(bucketMin, Integer.MAX_VALUE);
        Arrays.fill(bucketMax, Integer.MIN_VALUE);

        for (int i = 0; i < n; i++) {
            int bucketIndex = (nums[i] - min) / bucketSize;
            bucketMin[bucketIndex] = Math.min(bucketMin[bucketIndex], nums[i]);
            bucketMax[bucketIndex] = Math.max(bucketMax[bucketIndex], nums[i]);
        }

        int maxGap = 0;
        int preBucketMax = min;
        for (int i = 0; i < bucketCount; i++) {
            if (bucketMin[i] == Integer.MAX_VALUE) {
                continue;
            }
            maxGap = Math.max(maxGap, bucketMin[i] - preBucketMax);
            preBucketMax = bucketMax[i];
        }

        return maxGap;
    }
}