#include <iostream>
#include <vector>
#include <map>
using namespace std;

int maxSubArrayCount(vector<int> arr) {
    int n = arr.size();
    if(n == 0) {
        return 0;
    }
    map<int, int> m; // key：异或值  value：上一次有这个异或值时 i 的位置
    vector<int> dp(n, 0); // dp[i] 表示 arr[0...i] 中包含的最大的子数组异或数
    int eor = 0;
    m[0] = -1;
    for(int i = 0; i < n; i++) {
        eor ^= arr[i];
        if(m.count(eor)) {
            int preEorIndex = m[eor];
            dp[i] = preEorIndex == -1 ? 1 : (dp[preEorIndex] + 1);
        }
        dp[i] = max(dp[i], dp[i - 1]);
        m[eor] = i;
    }
    
    return dp[n - 1];
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << maxSubArrayCount(arr);
    
    return 0;
}