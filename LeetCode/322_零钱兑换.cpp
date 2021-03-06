class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount < 0) {
            return -1;
        }
        
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for(int coin : coins) {
            for(int j = coin; j <= amount; j++) {
                if(dp[j - coin] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j - coin] + 1);
                }                
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0 || coins.size() == 0) {
            return 0;
        }
        vector<int> dp(amount + 1, 0); // dp[i] 表示构成总价值为 i 的情况下最少需要的钱币数目
        for(int coin : coins) {
            for(int i = coin; i <= amount; i++) {
                if(i == coin) {
                    dp[i] = 1;
                } else if(dp[i] == 0 && dp[i - coin] != 0) {
                    dp[i] = dp[i - coin] + 1;
                } else if(dp[i - coin] != 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] == 0 ? -1 : dp[amount];
    }
};