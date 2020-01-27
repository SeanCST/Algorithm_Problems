#include <iostream>
#include <vector>
using namespace std;

int minHP(vector<vector<int>> data) {
    if(data.size() <= 0 || data[0].size() <= 0) {
        return 0;
    }
    int row = data.size();
    int col = data[0].size();
    // dp[i][j] 表示走到 i j 位置时最起码应该具备的血量
    vector<vector<int>> dp(row--, vector<int>(col--, 0));
    dp[row][col] = data[row][col] > 0 ? 1 : -data[row][col] + 1;
    for(int j = col - 1; j >= 0; j--) {
        dp[row][j] = max(dp[row][j + 1] - data[row][j], 1); 
    }
    for(int i = row - 1; i >= 0; i--) {
        dp[i][col] = max(dp[i + 1][col] - data[i][col], 1); 
        for(int j = col - 1; j >= 0; j--) {
            int right = max(dp[i][j + 1] - data[i][j], 1);
            int down = max(dp[i + 1][j] - data[i][j], 1);
            dp[i][j] = min(right, down);
        }
    }
    
    return dp[0][0];
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> data(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> data[i][j];
        }
    }
    
    cout << minHP(data);
    
    return 0;
}