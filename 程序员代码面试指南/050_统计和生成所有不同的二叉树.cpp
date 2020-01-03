#include <iostream>
#include <vector>
using namespace std;

int getInOrderTreeNumber(int n) { 
    if(n <= 1) {
        return 1;
    }
    vector<long long> num(n + 1, 0);
    num[0] = 1;
    for(int i = 1; i <= n; i++) {
        long long tmp = 0;
        for(int j = 1; j <= i; j++) {
            tmp += num[j - 1] * num[i - j];      
            tmp = tmp % 1000000007;
        }
        num[i] = tmp;
    }
    
    return num[n];
}

int main() {
    int n;
    cin >> n;
    
    cout << getInOrderTreeNumber(n);
    
    return 0;
}