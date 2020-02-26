class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int fstBuy = INT_MIN, fstSell = 0;
        int secBuy = INT_MIN, secSell = 0;
        for(int p : prices) {
            fstBuy = max(fstBuy, -p);
            fstSell = max(fstSell, fstBuy + p);
            secBuy = max(secBuy, fstSell - p);
            secSell = max(secSell, secBuy + p);
        }

        return secSell;
    }
};