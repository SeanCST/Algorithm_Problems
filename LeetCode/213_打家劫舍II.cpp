class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0;
        int prev2 = 0;
        int n = nums.size();

        if(n == 1) {
            return nums[0];
        }

        for(int i = 0; i < n - 1; i++) {
            int sum = prev2 + nums[i];
            prev2 = prev1;
            prev1 = max(prev1, sum);
        }
        int maxValue = prev1;
        
        prev1 = 0;
        prev2 = 0;
        for(int i = 1; i < n; i++) {
            int sum = prev2 + nums[i];
            prev2 = prev1;
            prev1 = max(prev1, sum);
        }
        maxValue = max(prev1, maxValue);
        
        return maxValue;
    }
};