#include <iostream>
#include <vector>
using namespace std;

// 空间复杂度 O(m * n)
// int shortestPathSum(vector<vector<int>> arr) {
//     int m = arr.size();
//     int n = arr[0].size();
//     if(m == 0 || n == 0) {
//         return 0;
//     }
//     for(int i = 1; i < m; i++) {
//         arr[i][0] += arr[i - 1][0];
//     }
//     for(int j = 1; j < n; j++) {
//         arr[0][j] += arr[0][j - 1];
//     }
//     for(int i = 1; i < m; i++) {
//         for(int j = 1; j < n; j++) {
//             arr[i][j] = min(arr[i - 1][j], arr[i][j - 1]) + arr[i][j];
//         }
//     }
    
//     return arr[m - 1][n - 1];
// }

// 空间复杂度 O(max(m, n))
int shortestPathSum(vector<vector<int>> arr) {
    int m = arr.size();
    int n = arr[0].size();
    if(m == 0 || n == 0) {
        return 0;
    }
    int more = max(m, n);
    int less = min(m, n);
    bool rowMore = m > n;
    
    vector<int> dp(less, 0);
    dp[0] = arr[0][0];
    for (int i = 1; i < less; i++) {
        dp[i] = dp[i - 1] + (rowMore ? arr[0][i] : arr[i][0]);
    }

    for(int i = 1; i < more; i++) {
        dp[0] = dp[0] + (rowMore ? arr[i][0] : arr[0][i]);
        for(int j = 1; j < less; j++) {
            dp[j] = min(dp[j - 1], dp[j]) + (rowMore ? arr[i][j] : arr[j][i]);
        }
    }
    
    return dp[less - 1];
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    
    cout << shortestPathSum(arr);
    
    return 0;
}