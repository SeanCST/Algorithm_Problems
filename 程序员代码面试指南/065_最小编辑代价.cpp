#include <iostream>
#include <string>
#include <vector>
using namespace std;

// // 时间复杂度 O(m * n)  空间复杂度 O(m * n)
// int minCost(string s1, string s2, int ic, int dc, int rc) {
//     int m = s1.length();
//     int n = s2.length();
//     // dp[i][j] 代表 s1[0...i-1] 编辑成 s2[0...j-1] 的最小代价
//     vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//     for(int i = 1; i <= m; i++){
//         dp[i][0] = dc * i;
//     }
//     for(int j = 1; j <= n; j++){
//         dp[0][j] = ic * j;
//     }
//     for(int i = 1; i <= m; i++){
//         for(int j = 1; j <= n; j++){
//             if(s1[i - 1] == s2[j - 1]) {
//                 dp[i][j] = dp[i - 1][j - 1];
//             } else {
//                 dp[i][j] = dp[i - 1][j - 1] + rc;
//             }
//             dp[i][j] = min(dp[i][j], dp[i - 1][j] + dc);
//             dp[i][j] = min(dp[i][j], dp[i][j - 1] + ic);
//         }
//     }
    
//     return dp[m][n];
// }

// 时间复杂度 O(m * n)  空间复杂度 O(min(m, n))
int minCost(string s1, string s2, int ic, int dc, int rc) {
    string longs = s1.length() >= s2.length() ? s1 : s2;
    string shorts = s1.length() < s2.length() ? s1 : s2;
    int m = longs.length();
    int n = shorts.length();
    vector<int> dp(n + 1, 0);
    for(int i = 1; i <= n; i++){
        dp[i] = ic * i;
    }
    for(int i = 1; i <= m; i++){
        int pre = dp[0]; // pre 表示左上角的值
        dp[0] = i * dc;
        for(int j = 1; j <= n; j++){
            int tmp = dp[j]; // dp[j] 没更新之前先保存下来
            if(longs[i - 1] == shorts[j - 1]) {
                dp[j] = pre;
            } else {
                dp[j] = pre + rc;
            }
            dp[j] = min(dp[j], dp[j - 1] + ic);
            dp[j] = min(dp[j], tmp + dc);
            pre = tmp;
        }
    }
    
    return dp[n];
}

int main() {
    string str1, str2;
    int ic, dc, rc;
    cin >> str1 >> str2;
    cin >>ic >> dc >> rc;
    
    cout << minCost(str1, str2, ic, dc, rc);
    
    return 0;
}