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


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if(nums.empty()) {
            return res;    
        }
        int n = nums.size();
        int l = 0, r = n - 1;

        while(l < r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if(nums[l] != target) {
            return res;
        }
        res[0] = l;

        r = n; // 指向 n 而不是 n-1     
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) {
                l = mid + 1; // 最终 l 指向第一个大于 target 的数
            } else {
                r = mid;
            }
        }
        res[1] = l - 1;

        return res;
    }
};