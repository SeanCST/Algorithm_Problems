class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool modified = false;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i-1]) {
                if(modified) {
                    return false;
                } else {
                    // 若nums[i]比前两个都要小，则不得不改变nums[i]
                    if(i - 2 >= 0 && nums[i] < nums[i-2]) { 
                        nums[i] = nums[i-1];
                    }
                    // 优先考虑改变nums[i-1]，因为改变nums[i]可能会影响到下一次的判断
                    else { 
                        nums[i-1] = nums[i];
                    }
                    modified = true;
                }
            }
        }
        
        return true;
    }
};

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size() < 3) {
            return true;
        }
        bool modified = false;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i - 1] <= nums[i]) {
                continue;
            }
            if(modified) {
                return false;
            }
            if(i - 2 >= 0 && nums[i - 2] > nums[i]) {
                nums[i] = nums[i - 1];
            } else {
                nums[i - 1] = nums[i];
            }
            modified = true;
        }

        return true;
    }
};