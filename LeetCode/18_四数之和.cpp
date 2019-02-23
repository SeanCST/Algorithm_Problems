class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size() < 4) return res;
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 3; i++) {
            if(i == 0 || nums[i] > nums[i - 1]) { // 避免重复
                int three_target = target - nums[i]; // 减去第一个数之后的三数之后
                for(int j = i + 1; j < nums.size() - 2; j++) {
                    if(j == i + 1 || nums[j] > nums[j - 1]) { // 避免重复
                        int left = j + 1, right = nums.size() - 1;
                        while(left < right) {
                            if(nums[left] + nums[right] + nums[j] == three_target) {
                                res.push_back({nums[i], nums[j], nums[left], nums[right]});
                                while(left < right && nums[left] == nums[left + 1])  // 避免重复
                                    left++;
                                while(left < right && nums[right] == nums[right - 1])  // 避免重复
                                    right--;
                                left++;
                                right--;
                            } else if(nums[left] + nums[right] + nums[j] < three_target) {
                                left++;
                            } else {
                                right--;
                            }
                        }
                    }
                }
            }
        }
        
        return res;
    }
};