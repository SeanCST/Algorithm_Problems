class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n <= 1 || k < 1) {
            return 0;
        }
        if(k >= n / 2) {
            return greedy(prices);
        }

        vector<vector<int>> dp(k, vector<int>(2, 0));
        for(int i = 0; i < k; i++) {
            dp[i][0] = INT_MIN;
        }
        for(int p : prices) {
            dp[0][0] = max(dp[0][0], -p);
            dp[0][1] = max(dp[0][1], dp[0][0] + p);
            for(int i = 1; i < k; i++) {
                dp[i][0] = max(dp[i][0], dp[i - 1][1] - p); // 买
                dp[i][1] = max(dp[i][1], dp[i][0] + p); // 卖
            }
        }

        return dp[k - 1][1];
    }

    int greedy(vector<int>& prices) {
        int maxProfit = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i - 1]) {
                maxProfit += prices[i] - prices[i - 1];
            }
        }

        return maxProfit;
    }
};