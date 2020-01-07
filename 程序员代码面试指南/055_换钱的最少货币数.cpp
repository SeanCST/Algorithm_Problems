#include <iostream>
#include <vector>
using namespace std;

int minCurrencyNum(vector<int> arr, int aim) {
    
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