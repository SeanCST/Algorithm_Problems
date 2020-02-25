class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) {
            return 0;
        }

        vector<int> buy(n, 0); // buy[i] 表示第 i 天进行买入时，现在跟原始钱的差距
        vector<int> s1(n, 0); // s1[i] 表示第 i 天不操作时，现在跟原始钱的差距
        vector<int> sell(n, 0); // sell[i] 表示第 i 天进行卖出时，现在跟原始钱的差距
        vector<int> s2(n, 0); // s2[i] 表示第 i 天进行不操作时，现在跟原始钱的差距
 
        s1[0] = buy[0] = -prices[0];
        s2[0] = sell[0] = 0;

        for(int i = 1; i < n; i++) {
            buy[i] = s2[i - 1] - prices[i]; // 只能用前一天的 s2 来减，因为前一天不能交易
            s1[i] = max(buy[i - 1], s1[i - 1]); // 今天不进行操作所获得的的最大值
            sell[i] = max(buy[i - 1], s1[i - 1]) + prices[i]; // 今天进行卖出操作所能获取到的较大值
            s2[i] = max(sell[i - 1], s2[i - 1]); // 今天不进行操作所获得的的最大值
        }

        return max(s2[n - 1], sell[n - 1]);
    }
};