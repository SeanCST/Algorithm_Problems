class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int res = nums[0], temp = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            temp += nums[i];
            if (temp > res) {
                res = temp;
            }
            if (temp < 0) {
                temp = 0;
            }
            
        }
        
        return res;
    }
};