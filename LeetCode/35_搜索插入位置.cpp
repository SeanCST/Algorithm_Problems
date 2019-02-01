class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0 || nums[0] > target) {
            return 0;
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target) {
                return i;
            } else if (i < nums.size() - 1 && nums[i] < target && nums[i+1] > target) {
                return i + 1;
            }
        }
        
        // 以上情况都不满足，则将 target 插入到最后一位
        return nums.size();
    }
};