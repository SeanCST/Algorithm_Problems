class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;

        int l = 0, r = n - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[r]) { // mid...r in order
                r = mid;
            } else if (nums[mid] > nums[r]) { // l...mid in order
                l = mid + 1;
            } else {
                int i = l;
                while (i < r && nums[i] >= nums[r]) {
                    i++;
                }
                return nums[i];
            }
        }

        return nums[l];
    }
}

// class Solution {
//     public int findMin(int[] nums) {
//         int l = 0, r = nums.length - 1;

//         while (l < r) {
//             int mid = l + (r - l) / 2;
//             if (nums[mid] > nums[r]) {
//                 l = mid + 1;
//             } else if (nums[mid] < nums[r]) {
//                 r = mid;
//             } else {
//                 int x = l;
//                 for (int k = l + 1; k < r; k++) {
//                     if (nums[k] < nums[x]) {
//                         x = k;
//                     }
//                 }
//                 return nums[x];
//             }
//         }

//         return nums[l];
//     }
// }