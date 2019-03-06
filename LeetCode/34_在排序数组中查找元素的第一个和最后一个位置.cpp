class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1, -1};

        int first  = binarySearchFirst(nums, target);
        int last = binarySearchFirst(nums, target + 1) - 1;
        
        if(first == nums.size() || nums[first] != target) {
            return res; // 不存在            
        } else {
            res[0] = first;
            res[1] = max(first, last);
            return res;
        }
    }
    
    int binarySearchFirst(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};