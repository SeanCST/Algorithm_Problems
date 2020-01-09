#include <iostream>
#include <vector>
using namespace std;

// int changeMethodNum(vector<int> arr, int aim) {
//     int N = arr.size();
//     if(N == 0 || aim < 0) {
//         return 0;
//     }
    
//     // dp[i][j] 代表使用 arr[0...i] 这些货币的情况下 置换 钱价值为 aim  的方法数
//     vector<vector<int>> dp(N, vector<int>(aim + 1, 0));
    
//     for(int i = 0; i < N; i++) {
//         dp[i][0] = 1;
//     }
//     for(int j = 0; j * arr[0] <= aim; j++) {
//         dp[0][j * arr[0]] = 1;
//     }
//     int mod = 1000000007;
//     for(int i = 1; i < N; i++) {
//         for(int j = 1; j <= aim; j++) {
//             dp[i][j] = dp[i - 1][j]; // 不使用 arr[i] 的方法数
//             dp[i][j] += j - arr[i] >= 0 ? dp[i][j - arr[i]] : 0; // 加上 使用 大于等于一张 arr[i] 的方法数
//             dp[i][j] = dp[i][j] % mod;
//         }
//     }
    
//     return dp[N - 1][aim];
// }

int changeMethodNum(vector<int> arr, int aim) {
    int N = arr.size();
    if(N == 0 || aim < 0) {
        return 0;
    }
    
    vector<int> dp(aim + 1, 0);
    
    for(int j = 0; j * arr[0] <= aim; j++) {
        dp[j * arr[0]] = 1;
    }
    int mod = 1000000007;
    for(int i = 1; i < N; i++) {
        dp[0] = 1;
        for(int j = 1; j <= aim; j++) {
            dp[j] += j - arr[i] >= 0 ? dp[j - arr[i]] : 0; // 加上 使用 大于等于一张 arr[i] 的方法数
            dp[j] = dp[j] % mod;
        }
    }
    
    return dp[aim];
}

int main() {
    int n, aim;
    cin >> n >> aim;
    
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << changeMethodNum(arr, aim);
    
    return 0;
}