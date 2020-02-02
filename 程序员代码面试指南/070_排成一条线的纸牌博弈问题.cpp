#include <iostream>
#include <vector>
// #include <algorithm>
using namespace std;

int winnerScore(vector<int> arr) {
    int n = arr.size();
    if(n == 0) {
        return 0;
    }
    vector<vector<int>> dpF(n, vector<int>(n, 0)); // 先拿
    vector<vector<int>> dpS(n, vector<int>(n, 0)); // 后拿
    
    for(int i = 0; i < n; i++) {
        dpF[i][i] = arr[i];
        dpS[i][i] = 0;
        for(int j = i - 1; j >= 0; j--) {
            dpF[j][i] = max(arr[j] + dpS[j + 1][i], arr[i] + dpS[j][i - 1]);
            dpS[j][i] = min(dpF[j][i - 1], dpF[j + 1][i]);
        }
    }
    
    return max(dpF[0][n - 1], dpS[0][n - 1]);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << winnerScore(arr);
    
    return 0;
}