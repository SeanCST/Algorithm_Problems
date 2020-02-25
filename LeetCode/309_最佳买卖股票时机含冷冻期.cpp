class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) {
            return 0;
        }

        vector<int> buy(n, 0);  // buy[i] 表示第 i 天进行买入时，现在跟原始钱的差距
        vector<int> sell(n, 0); // sell[i] 表示第 i 天进行卖出时，现在跟原始钱的差距
        vector<int> cool(n, 0); // cool[i] 表示第 i 天进行不操作时，现在跟原始钱的差距
 
        buy[0] = -prices[0];

        for(int i = 1; i < n; i++) {
            sell[i] = buy[i - 1] + prices[i];
            buy[i] = max(cool[i - 1] - prices[i], buy[i - 1]);
            cool[i] = max(sell[ i - 1], cool[i - 1]);
        }

        return max(cool[n - 1], sell[n - 1]);
    }
};