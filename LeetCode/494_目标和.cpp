class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        // return find(nums, 0, S);

        // sum(P) - sum(N) = target
        // sum(P) - sum(N) + sum(P) + sum(N) = target + sum(nums)
        // 2 * sum(P) = target + sum(nums)
        // sum(P) = (target + sum(nums)) / 2
        // 对值 sum(P) 以 0-1 背包方法解决

        if(nums.size() == 0) {
            return 0;
        }
        
        long long sum = 0;
        for(int num : nums) {
            sum += num;
        }
        if((S + sum) % 2 == 1 || S > sum) {
            return 0;
        }
        int target = (S + sum) / 2;
        
        // 0-1 背包刚好装满的问题
        vector<int> dp(target + 1, 0);
        dp[0] = 1; // 初始化和为 0 的情况：全部都不选，方案数为 1
        for(int num : nums) {
            for(int j = target; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }
        
        return dp[target];
    }

    // int find(vector<int>& nums, int start, int S) {
    //     if(start == nums.size()) {
    //         return S == 0 ? 1 : 0;
    //     }

    //     return find(nums, start + 1, S + nums[start]) 
    //           +find(nums, start + 1, S - nums[start]);
    // }
};