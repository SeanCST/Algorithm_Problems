class Solution {
    public boolean search(int[] nums, int target) {
        int len = nums.length;
        
        int l = 0, r = len - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) {
                return true;
            } 

            if(nums[l] == nums[mid]) { // 无法判断哪半部分有序
                l++;
                continue;
            }

            if(nums[l] < nums[mid]) { // 前半部分有序
                if(nums[l] <= target && nums[mid] > target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else { // 后半部分有序
                if(nums[r] >= target && nums[mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return false;
    }
}