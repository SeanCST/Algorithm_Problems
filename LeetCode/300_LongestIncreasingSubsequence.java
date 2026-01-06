class Solution {
    public int lengthOfLIS(int[] nums) {
        int len = nums.length;
        int[] tails = new int[len];
        int res = 0;
        for (int num : nums) {
            int l = 0, r = res;
            while (l < r) {
                int m = l + (r - l) / 2;
                if (tails[m] < num) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            tails[l] = num;
            if (l == res) {
                res++;
            }
        }

        return res;
    }
}

// class Solution {
//     public int lengthOfLIS(int[] nums) {
//         int len = nums.length;
//         if (len == 0) {
//             return 0;
//         }
//         int[] dp = new int[len];
//         int res = 1;
//         Arrays.fill(dp, 1);
//         for (int i = 0; i < len; i++) {
//             for (int j = 0; j < i; j++) {
//                 if (nums[i] > nums[j]) {
//                     dp[i] = Math.max(dp[i], dp[j] + 1);
//                 }
//             }
//             res = Math.max(dp[i], res);
//         }

//         return res;
//     }
// }