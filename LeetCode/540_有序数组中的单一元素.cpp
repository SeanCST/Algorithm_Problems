class Solution {
    public int singleNonDuplicate(int[] nums) {
        int n = nums.length;

        int l = 0, r = n - 1;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(mid % 2 == 0) { 
                if(nums[mid] != nums[mid + 1]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            } else { 
                if(nums[mid] == nums[mid - 1]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
        }

        return nums[l];
    }
}

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

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == nums[mid - 1]) {
                if((mid - left) % 2 == 0) { // left~mid 有奇数个数
                    right = mid - 2;
                } else {
                    left = mid + 1;
                }
            } else if(nums[mid] == nums[mid + 1]) {
                if((mid - left) % 2 == 0) { // left~mid 有奇数个数
                    left = mid + 2;
                } else {
                    right = mid - 1;
                }
            } else {
                return nums[mid];
            }
        }

        return nums[left];
    }
};