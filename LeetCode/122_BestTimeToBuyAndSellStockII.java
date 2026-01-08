class Solution {
    public int maxProfit(int[] prices) {
        int res = 0;
        // int buy = prices[0];
        for (int i = 1; i < prices.length; i++) {
            res += Math.max(0, prices[i] - prices[i - 1]);
            // if (prices[i] > buy) {
            //     res += prices[i] - buy;
            // } 
            // buy = prices[i]; 
        }

        return res;
    }
}