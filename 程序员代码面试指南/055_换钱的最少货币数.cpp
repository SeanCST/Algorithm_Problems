#include <iostream>
#include <vector>
using namespace std;

int minCurrencyNum(vector<int> arr, int aim) {
    if(arr.size() == 0 || aim < 0) {
        return -1;
    }
    int N = arr.size();
    vector<vector<int>> dp(N + 1, vector<int>(aim + 1, 0));
    // 只有 dp[N][0] 为 0，其他为 -1。
    // 因为查询完数组中的所有数之后剩余的 aim 为 0，即为完成，其他都为 -1 表示本次查询结果失败。
    for(int i = 1; i <= aim; i++) {
        dp[N][i] = -1;
    }
    for(int i = N - 1; i >= 0; i--) {
        for(int rest = 0; rest <= aim; rest++) {
            dp[i][rest] = -1;

            if(dp[i + 1][rest] != -1) {
                dp[i][rest] = dp[i + 1][rest];
            }
            // 如果左边不越界且有效
            if(rest - arr[i] >= 0 && dp[i][rest - arr[i]] != -1) {
                if(dp[i][rest] == -1) {
                    dp[i][rest] = dp[i][rest - arr[i]] + 1;
                } else {
                    dp[i][rest] = min(dp[i][rest], dp[i][rest - arr[i]] + 1);
                }
            }
        }
    }
    
    return dp[0][aim]; // 结果
}

int main() {
    int n, aim;
    cin >> n >> aim;
    
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << minCurrencyNum(arr, aim);
    
    return 0;
}