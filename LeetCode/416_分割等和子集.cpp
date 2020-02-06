class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if(sum % 2 == 1) {
            return false;
        }

        int W = sum / 2;
        vector<bool> dp(W + 1, false);
        dp[0] = true;
        
        for(int num : nums) {
            for(int i = W; i >= num; i--) {
                dp[i] = dp[i] || dp[i - num];
            }
        }        

        return dp[W];
    }
};