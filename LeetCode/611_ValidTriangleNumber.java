class Solution {
    public int triangleNumber(int[] nums) {
        Arrays.sort(nums);
        int ans = 0, n = nums.length;
        for (int i = 0; i < n - 2; i++) {
            int a = nums[i];
            if (a == 0) {
                continue;
            }
            int j = i + 1;
            for (int k = i + 2; k < n; k++) {
                while (nums[k] - nums[j] >= a) {
                    j++;
                }
                ans += k - j;
            }
        }

        return ans;
    }
}