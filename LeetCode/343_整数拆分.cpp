class Solution {
public:
    /*贪心法则：
    第一优先级： 3；把数字 n 拆成尽可能多的 3 之和；
    特殊情况： 拆完后，如果余数是 1；则应把最后的 3 + 1 替换为 2 + 2，因为后者乘积更大；
    第二优先级： 2；留下的余数如果是 2，则保留，不再拆为 1+1。
    */
    int integerBreak(int n) {
        if(n <= 3) {
            return n - 1;
        }
        int a = n / 3, b = n % 3;
        if(b == 0) {
            return pow(3, a);
        } 
        if(b == 1) {
            return pow(3, a - 1) * 4;
        }
        return pow(3, a) * 2;
    }

    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j < i; j++) {
                dp[i] = max(dp[i], j * max(dp[i - j], i - j));
            }
        }

        return dp[n];
    }
};