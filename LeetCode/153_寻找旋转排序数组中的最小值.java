class Solution {
    public int findMin(int[] nums) {
        int l = 0, r = nums.length - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[r]) {
                r = mid;
            } else if (nums[mid] > nums[r]) {
                l = mid + 1;
            }
        }

        return nums[l];
    }
}

// class Solution {
//     public int findMin(int[] nums) {
//         int len = nums.length;
//         if(len == 1) {
//             return nums[0];
//         }
//         int l = 0, r = len - 1;
//         if(nums[l] < nums[r]) { // 等于没旋转
//             return nums[l];
//         }

//         // 真实旋转了，必存在 nums[i - 1] > nums[i]，其中 nums[i] 为最小值
//         while(l < r) {
//             int mid = l + (r - l) / 2;
//             if(nums[mid] > nums[mid + 1]) { // 找到最小值
//                 return nums[mid + 1];
//             } else if(nums[l] < nums[mid]) { // 左边有序，最小值在右边
//                 l = mid + 1;
//             } else { // 右边有序，最小值在左边（包含 mid）
//                 r = mid;
//             }
//         }

//         return Math.min(nums[l], nums[r]);
//     }
// }