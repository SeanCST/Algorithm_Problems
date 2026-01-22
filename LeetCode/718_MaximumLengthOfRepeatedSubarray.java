class Solution {
    public int findLength(int[] nums1, int[] nums2) {
        int len1 = nums1.length, len2 = nums2.length;
        int[] dp = new int[len2];
        int res = 0;

        for (int i = 0; i < len1; i++) {
            for (int j = len2 - 1; j >= 0; j--) {
                if (nums1[i] == nums2[j]) {
                    dp[j] = (j > 0 ? dp[j - 1] : 0) + 1;
                    res = Math.max(res, dp[j]);
                } else {
                    dp[j] = 0;
                }
            }
        }

        return res;
    }
}