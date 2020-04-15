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
            if(dp[W]) {
                return true;
            }
        }        

        return dp[W];
    }
};

    bool canPartition(vector<int>& nums) {
        if(nums.size() == 0) {
            return true;
        }
        
        int sum = 0;
        for(int num : nums) {
            sum += num;
        }
        
        if(sum % 2 == 1) {
            return false;
        }
        int target = sum / 2;
        
        vector<vector<bool>> dp(nums.size(), vector<bool>(target + 1, false));
        if(nums[0] <= target) {
            dp[0][nums[0]] = true;
        }
        
        for(int i = 1; i < nums.size(); i++) {
            dp[i][0] = true;
            for(int j = 0; j <= target; j++) {
                if(j >= nums[i]) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
                }
            }

            if(dp[i][target]) {
                return true;
            }
        }
        
        return dp[nums.size() - 1][target];
    }