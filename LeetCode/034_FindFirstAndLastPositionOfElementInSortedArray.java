class Solution {
    public int[] searchRange(int[] nums, int target) {
        int start = lowerBound(nums, target);
        if (nums.length == 0 || nums[start] != target) {
            return new int[]{-1, -1};
        }
        int end = lowerBound(nums, target + 1);
        if (nums[end] > target) {
            end -= 1;
        }

        return new int[]{start, end};
    }

    private int lowerBound(int[] nums, int target) {
        int l = 0, r = nums.length - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if ((nums[m] >= target)) {
                if (m == 0 || nums[m - 1] < target) {
                    return m;
                } else {
                    r = m - 1;
                }
            } else {
                l = m + 1;
            }
        }

        return l;
    }
}

// class Solution {
//     public int[] searchRange(int[] nums, int target) {
//         int[] res = new int[2];
//         Arrays.fill(res, -1);

//         int find = findTarget(nums, target);
//         if (find == -1) {
//             return res;
//         }
//         res[0] = findFirst(nums, target, find);
//         res[1] = findLast(nums, target, find);

//         return res;
//     }

//     private int findFirst(int[] nums, int target, int r) {
//         int l = 0;
//         while (l < r) {
//             int m = l + (r - l) / 2;
//             if (nums[m] == target) {
//                 if (m == 0 || nums[m - 1] != target) {
//                     return m;
//                 } else {
//                     r = m;
//                 }
//             } else {
//                 l = m + 1;
//             }
//         }
//         return l;
//     }

//     private int findLast(int[] nums, int target, int l) {
//         int r = nums.length - 1;
//         while (l < r) {
//             int m = l + (r - l + 1) / 2;
//             if (nums[m] == target) {
//                 if (m == nums.length - 1 || nums[m + 1] != target) {
//                     return m;
//                 } else {
//                     l = m;
//                 }
//             } else {
//                 r = m - 1;
//             }
//         }
//         return l;
//     }

//     private int findTarget(int[] nums, int target) {
//         int l = 0, r = nums.length - 1;
//         while (l <= r) {
//             int m = l + (r - l) / 2;
//             if (nums[m] == target) {
//                 return m;
//             } else if (nums[m] > target) {
//                 r = m - 1;
//             } else {
//                 l = m + 1;
//             }
//         }

//         return -1;
//     }
// }