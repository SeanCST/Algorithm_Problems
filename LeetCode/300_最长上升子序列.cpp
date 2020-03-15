class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int maxLen = 0;
        for(int num : nums) {
            int l = 0, r = maxLen;
            while(l < r) {
                int mid = l + (r - l) / 2;
                if(dp[mid] < num) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            dp[l] = num;
            if(l == maxLen) {
                maxLen++;
            }
        }

        return maxLen;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {
            return 0;
        }
        // vector<int> dp(n, 0);
        // 有效区为 ends[0...right]，无效区为 ends[right+1 ... N-1]
        // 对有效区上的位置 b，如果有 ends[b] == c，表示遍历到目前为止，
        // 在所有长度为 b+1 的递增序列中，最小的结尾数是 c
        vector<int> ends(n, 0);
        // dp[0] = 1;
        ends[0] = nums[0];
        int right = 0;
        int l = 0, r = 0, m = 0;
        int maxLen = 1;
        for (int i = 1; i < n; i++) {
            l = 0;
            r = right;
            while(l <= r) {
                m = (l + r) / 2;
                if(nums[i] > ends[m]){
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            right = max(right, l);
            ends[l] = nums[i];
            // dp[i] = l + 1;
            // maxLen = max(maxLen, dp[i]);
            maxLen = max(maxLen, l + 1);
        }

        return maxLen;
    }

    
};