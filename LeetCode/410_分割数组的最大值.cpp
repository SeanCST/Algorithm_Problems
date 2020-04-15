class Solution {
public:
    int splitArray(vector<int>& nums, int m) { // 二分法
        int n = nums.size();

        long long sum = 0;
        long long maxNum = 0;
        for(int num : nums) {
            sum += num;
            if(num > maxNum) {
                maxNum = num;
            }
        }
        
        if(m == n) { // 每组都只包含一个数
            return maxNum;
        }

        // 结果肯定满足 maxNum <= res <= sum
        int low = maxNum, high = sum;
        while(low < high) {
            long long mid = low + (high - low) / 2; // mid 表示猜测的结果
            int temp = 0, cnt = 1;
            for(int num : nums) {
                temp += num;
                if(temp > mid) { // 前一个子数组的和超过了猜测的结果，再加一个子数组
                    temp = num;
                    cnt++;
                }
            }

            if(cnt > m) { // 划分的子数组个数大于 m，表示猜测的结果设小了，需要增大
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        
        vector<long long> subSum(n + 1, 0);
        for(int i = 0; i < n; i++) {
            subSum[i + 1] = subSum[i] + nums[i];
        }

        // dp[i][j] 表示 nums[0 ... i - 1] 被划分为 j 个子数组，
        // 各情况下各子数组和最大值的最小情况的值
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, INT_MAX));
        dp[0][0] = 0;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                for(int k = 0; k < i; k++) {
                    dp[i][j] = min(dp[i][j], max(dp[k][j - 1], subSum[i] - subSum[k]));
                }
            }
        }

        return dp[n][m];
    }
};