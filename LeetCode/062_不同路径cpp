class Solution {
public:
    // int uniquePaths(int m, int n) {
    //     if(m == 0 || n == 0) {
    //         return 1;
    //     }
    //     vector<int> dp(n, 1);
    //     for(int i = 1; i < m; i++) {
    //         for(int j = 1; j < n; j++) {
    //             dp[j] = dp[j - 1] + dp[j];
    //         }
    //     }

    //     return dp[n - 1];
    // }

    int uniquePaths(int m, int n) {
        if(m == 0 || n == 0) {
            return 1;
        }
        
        // 组合数的方法
        int S = m + n - 2;
        int D = m - 1;
        long res = 1;
        for(int i = 1; i <= D; i++) {
            res = res * (S - D + i) / i;
        }
        return res; // C(S, D) = S! / ((S - D)! * D!)
    }
};