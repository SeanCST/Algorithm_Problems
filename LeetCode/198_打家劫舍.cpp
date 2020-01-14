class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0, prev2 = 0;
        for(int i = 0; i < nums.size(); i++) {
            int sum = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = sum;
        }

        return prev1;
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        int take = 0, notTake = 0, maxProfit = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            take = notTake + nums[i]; // 坷
            notTake = maxProfit; // 丝坷
            maxProfit = max(take, notTake);
        }
        return maxProfit;
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        if(n == 1)
            return nums[0];
        
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];
        for(int i = 2; i < n; i++) {
            int take = dp[i - 2] + nums[i];
            dp[i] = take > dp[i - 1] ? take : dp[i - 1]; 
        }
        
        return dp[n - 1];
    }
};