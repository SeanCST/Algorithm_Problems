class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) {
            return 0;
        }

        vector<int> buy(n, 0);  // buy[i] 最后一个操作是买入的最大收益
        vector<int> sell(n, 0); // sell[i] 最后一个操作是卖出的最大收益
        vector<int> cool(n, 0); // cool[i] 最后一个操作是冷冻的最大收益
 
        buy[0] = -prices[0];

        for(int i = 1; i < n; i++) {
            sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);
            buy[i] =  max(cool[i - 1] - prices[i], buy[i - 1]);
            cool[i] = max(sell[i - 1], cool[i - 1]);
        }

        return max(cool[n - 1], sell[n - 1]);
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        if(n <= 1) {
            return 0;
        }

        // vector<int> buy(n, 0);
        // vector<int> sell(n, 0);
        // vector<int> frozen(n, 0);

        // buy[0] = 0 - prices[0];

        // for(int i = 1; i < n; i++) {
        //     sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);
        //     frozen[i] = max(sell[i - 1], frozen[i - 1]);
        //     buy[i] = max(buy[i - 1], frozen[i - 1] - prices[i]);
        // }

        // return max(sell[n - 1], frozen[n - 1]);

        int buy = 0 - prices[0];
        int sell = 0, frozen = 0;

        int oldBuy, oldSell, oldFrozen;
        for(int i = 1; i < n; i++) {
            oldBuy = buy;
            oldSell = sell;
            oldFrozen = frozen;

            sell = max(oldBuy + prices[i], oldSell);
            frozen = max(oldSell, oldFrozen);
            buy = max(oldBuy, oldFrozen - prices[i]);
        }

        return max(sell, frozen);
    }
};