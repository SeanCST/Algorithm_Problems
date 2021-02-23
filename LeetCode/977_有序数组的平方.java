class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];

        int l = 0, r = n - 1, k = n - 1;
        while(l <= r) {
            if(Math.abs(nums[l]) >= Math.abs(nums[r])) {
                res[k--] = nums[l] * nums[l];
                l++;
            } else {
                res[k--] = nums[r] * nums[r];
                r--;
            }
        }

        return res;
    }
}


// class Solution {
//     public int[] sortedSquares(int[] nums) {
//         int n = nums.length;
//         int[] res = new int[n];
//         int start = 0;
        
//         if(nums[0] < 0 && nums[n - 1] >= 0) {
//             for(int i = 0; i < n - 1; i++) {
//                 if(nums[i] < 0 && nums[i + 1] >= 0) {
//                     start = Math.abs(nums[i]) < Math.abs(nums[i + 1]) ? i : i + 1;
//                     break;
//                 }
//             }
//         } else if(nums[n - 1] <= 0) {
//             start = n - 1;
//         }

//         int k = 0;
//         res[k++] = nums[start] * nums[start];
//         int l = start - 1, r = start + 1;
//         while(k < n) {
//             if(l >= 0 && r < n) {
//                 if(Math.abs(nums[l]) <= Math.abs(nums[r])) {
//                     res[k++] = nums[l] * nums[l];
//                     l--;
//                 } else {
//                     res[k++] = nums[r] * nums[r];
//                     r++;
//                 }
//             } else if(l < 0) {
//                 res[k++] = nums[r] * nums[r];
//                 r++;
//             } else if(r >= n) {
//                 res[k++] = nums[l] * nums[l];
//                 l--;
//             }
//         }

//         return res;
//     }
// }