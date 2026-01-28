class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int n = nums.length, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if (sum % k > 0) {
            return false;
        }

        int target = sum / k;
        Arrays.sort(nums);
        reverse(nums);
        if (nums[0] > target) {
            return false;
        }

        int[] backets = new int[k];
        return backtrace(nums, backets, target, 0);
    }

    private boolean backtrace(int[] nums, int[] buckets, int target, int k) {
        if (k == nums.length) {
            return true;
        }
        int cur = nums[k];
        for (int i = 0; i < buckets.length; i++) {
            if (buckets[i] + cur > target) {
                continue;
            }

            buckets[i] += cur;
            if (backtrace(nums, buckets, target, k + 1)) {
                return true;
            }
            buckets[i] -= cur;

            if (buckets[i] == 0) {
                break;
            }
        }
        return false;
    }

    private void reverse(int[] nums) {
        int l = 0, r = nums.length - 1;
        while (l < r) {
            int temp = nums[l];
            nums[l++] = nums[r];
            nums[r--] = temp;
        }
    }
}