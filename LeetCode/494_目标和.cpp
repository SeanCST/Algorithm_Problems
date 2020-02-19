class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        // return find(nums, 0, S);

        // sum(P) - sum(N) = target
        // sum(P) - sum(N) + sum(P) + sum(N) = target + sum(nums)
        // 2 * sum(P) = target + sum(nums)
        // sum(P) = (target + sum(nums)) / 2
        // 对值 sum(P) 以 0-1 背包方法解决

        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if(sum < S || (S + sum) % 2 == 1) {
            return 0;
        }
        int sumP = (S + sum) / 2;
        
        vector<int> dp(sumP + 1, 0);
        dp[0] = 1;
        for(int num : nums) {
            for(int j = sumP; j >= num; j--) {
                dp[j] += dp[j - num];                
            }
        }

        return dp[sumP];
    }

    // int find(vector<int>& nums, int start, int S) {
    //     if(start == nums.size()) {
    //         return S == 0 ? 1 : 0;
    //     }

    //     return find(nums, start + 1, S + nums[start]) 
    //           +find(nums, start + 1, S - nums[start]);
    // }
};