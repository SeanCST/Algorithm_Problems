class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, h = nums.size() - 1;
        while(l < h) {
            int mid = l + (h - l) / 2;
            if(nums[mid] <= nums[h]) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return nums[l];
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int mid = 0;
        while(l < r) {
            mid = l + (r - l) / 2;
            if(nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            } else if(nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return nums[l];
    }
};