class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if(n <= 1) {
            return 0;
        }

        vector<int> buy(n, 0);
        vector<int> sell(n, 0);

        buy[0] = -prices[0];

        for(int i = 1; i < n; i++) {
            sell[i] = max(buy[i - 1] + prices[i] - fee, sell[i - 1]);
            buy[i] = max(sell[i - 1] - prices[i], buy[i - 1]);
        }

        return sell[n - 1];
    }
};