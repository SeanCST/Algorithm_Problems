#include <iostream>
#include <vector>
using namespace std;

// 空间复杂度 O(k * n)
// int ways(int n, int m, int p, int k) {
//     if(n < 2 || k < 1 || m < 1 || m > n || p < 1 || p > n) {
//         return 0;
//     }

//     int mod = 1000000007;
    
//     // 行代表剩余步数的所有情况，列代表来到位置的所有情况
//     vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
//     dp[0][p] = 1;
//     for(int i = 1; i <= k; i++) {
//         for(int j = 1; j <= n; j++) {
//             if(j == 1) {
//                 dp[i][j] = dp[i - 1][2];
//             } else if(j == n) {
//                 dp[i][j] = dp[i - 1][n - 1];
//             } else {
//                 dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
//             }
//         }
//     }
    
//     return dp[k][m];
// }

// 空间复杂度 O(k * n)
int ways(int n, int m, int p, int k) {
    if(n < 2 || k < 1 || m < 1 || m > n || p < 1 || p > n) {
        return 0;
    }

    int mod = 1000000007;
    
    vector<int> dp(n + 1, 0);
    dp[p] = 1;
    for(int i = 1; i <= k; i++) {
        int leftUp = dp[1]; // 左上角的值
        for(int j = 1; j <= n; j++) {
            int tmp = dp[j]; // 不停更新左上角的值，因为计算过程中它会被覆盖
            if(j == 1) {
                dp[j] = dp[j + 1];
            } else if(j == n) {
                dp[j] = leftUp;
            } else {
                dp[j] = (leftUp + dp[j + 1]) % mod;
            }
            leftUp = tmp;
        }
    }
    
    return dp[m];
}

int main() {
    int n, m, k, p;
    cin >> n >> m >> k >> p;
    
    cout << ways(n, m, p, k);
    
    return 0;
}