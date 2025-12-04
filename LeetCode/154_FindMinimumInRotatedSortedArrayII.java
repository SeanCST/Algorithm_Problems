class Solution {
    public int findMin(int[] nums) {
        int l = 0, r = nums.length - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else if (nums[mid] < nums[r]) {
                r = mid;
            } else {
                int x = l;
                for (int k = l + 1; k < r; k++) {
                    if (nums[k] < nums[x]) {
                        x = k;
                    }
                }
                return nums[x];
            }
        }

        return nums[l];
    }
}