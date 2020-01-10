#include <iostream>
#include <vector>
using namespace std;

int getMaxScore(vector<int> arr) {
    int N = arr.size();
    if(N == 0) {
        return 0;
    }
    if(N == 1) {
        return arr[0];
    }
    // 左右各添上一个 1
    vector<int> help(N + 2, 1);
    for(int i = 0; i < N; i++) {
        help[i + 1] = arr[i];
    }
    
    vector<vector<int>> dp(N + 2, vector<int>(N + 2, 0));
    // base case ：所有的 dp[L][R] 代表从 L 到 R 之内的最大值
    // dp[i][i] 即为范围内只有一个气球，直接打爆即可，打爆它能获得的分数为它的分数乘上两边的分数
    for(int i = 1; i <= N; i++) {
        dp[i][i] = help[i] * help[i - 1] * help[i + 1];
    }
    
    for(int L = N - 1; L >= 1; L--) {
        for(int R = L + 1; R <= N; R++) {
            // 最后打爆最左边
            int finalL = help[L] * help[L - 1] * help[R + 1] + dp[L + 1][R];
            // 最后打爆最右边
            int finalR = help[R] * help[L - 1] * help[R + 1] + dp[L][R - 1];
            dp[L][R] = max(finalL, finalR);
            // 遍历最后打爆中间的情况
            for(int k = L + 1; k < R; k++) {
                dp[L][R] = max(dp[L][R], 
                               help[L - 1] * help[k] * help[R + 1] + dp[L][k - 1] + dp[k + 1][R]);
            }
            
        }
    }
    
    return dp[1][N];
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << getMaxScore(arr);
    
    return 0;
}