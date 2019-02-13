class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1, mode = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if (mode == nums[i]) {
                count++;
            } else {
                count--;
            }
            
            if (count == 0) {
                count++;
                mode = nums[i];
            }
            
        }
        return mode;
    }
};