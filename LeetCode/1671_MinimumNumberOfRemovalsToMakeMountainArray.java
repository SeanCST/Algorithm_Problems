class Solution {
    public int minimumMountainRemovals(int[] nums) {
        int n = nums.length;
        if (n <= 2) {
            return 0;
        }

        int[] lis = getLISArray(nums);
        int[] reversed = reverse(nums);
        int[] lds = getLISArray(reversed);;
        lds = reverse(lds);

        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            if (lis[i] > 1 && lds[i] > 1) {
                maxLen = Math.max(maxLen, lis[i] + lds[i] - 1);
            }
        }

        return n - maxLen;
    }

    private int[] getLISArray(int[] nums) {
        int n = nums.length;
        int[] seq = new int[n];
        int[] dp = new int[n];

        int len = 0;
        for (int i = 0; i < n; i++) {
            int pos = binarySearch(seq, 0, len, nums[i]);
            if (pos == len) {
                seq[len++] = nums[i];
                dp[i] = len;
            } else {
                seq[pos] = nums[i];
                dp[i] = pos + 1;
            }
        }

        return dp;
    }

    private int binarySearch(int[] seq, int from, int to, int target) {
        int l = from, r = to;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (seq[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }

    private int[] reverse(int[] nums) {
        int n = nums.length;
        int[] reversed = new int[n];
        int l = 0, r = n - 1;
        while (l <= r) {
            reversed[l] = nums[r];
            reversed[r] = nums[l];
            l++;
            r--;
        }

        return reversed;
    }
}

// class Solution {
//     public int minimumMountainRemovals(int[] nums) {
//         int n = nums.length;
//         if (n <= 2) {
//             return 0;
//         }

//         int[] lis = new int[n];
//         int[] lds = new int[n];
//         Arrays.fill(lis, 1);
//         Arrays.fill(lds, 1);

//         for (int i = 1; i < n; i++) {
//             for (int j = 0; j < i; j++) {
//                 if (nums[j] < nums[i]) {
//                     lis[i] = Math.max(lis[i], lis[j] + 1);
//                 }
//             }
//         }

//         for (int i = n - 1; i >= 0; i--) {
//             for (int j = n - 1; j > i; j--) {
//                 if (nums[j] < nums[i]) {
//                     lds[i] = Math.max(lds[i], lds[j] + 1);
//                 }
//             }
//         }

//         int maxLen = 0;
//         for (int i = 0; i < n; i++) {
//             if (lis[i] > 1 && lds[i] > 1) {
//                 maxLen = Math.max(maxLen, lis[i] + lds[i] - 1);
//             }
//         }

//         return n - maxLen;
//     }
// }