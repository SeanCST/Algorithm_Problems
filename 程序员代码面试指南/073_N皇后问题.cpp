#include <iostream>
#include <vector>
using namespace std;
    
bool isValid(vector<int>& arr, int level) {
    for(int i = 0; i < level; i++) {
        if(arr[i] == arr[level] || abs(arr[level] - arr[i]) == level - i) {
            return false;
        }
    }
    
    return true;
}

int process(vector<int>& arr, int n, int level) {
    if(level == n) {
        return 1;
    }
    int res = 0;
    for(int i = 0; i < n; i++) {
        arr[level] = i;
        if(isValid(arr, level)) {
            res += process(arr, n, level + 1);
        }
    }
    
    return res;
}

int NQueens(int n) {
    if(n <= 0) {
        return 0;
    }    
    vector<int> arr(n, -1);
    return process(arr, n, 0);
}

int main() {
    int n;
    cin >> n;
    
    cout << NQueens(n);
    
    return 0;
}