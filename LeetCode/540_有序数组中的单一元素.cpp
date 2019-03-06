class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, h = nums.size() - 1;
        while(l < h) {
            int mid = l + (h - l) / 2;
            if(mid % 2 == 1) {
                mid--; // 保证 l/h/m 都在偶数位，使得查找区间大小一直都是奇数，结果必在奇数区间内
            }
            if(nums[mid] == nums[mid + 1]) {
                l = mid + 2;
            } else {
                h = mid;
            }
        }
        
        return nums[l];
    }
};