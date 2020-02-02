#include <iostream>
#include <vector>
using namespace std;

int minJump(vector<int> arr) {
    int n = arr.size();
    if(n == 0) {
        return 0;
    }
    int jump = 0; // 目前跳的步数
    int cur = 0; // 跳 jump 步最远能达到的位置
    int next = 0; // 再多跳一步最远能达到的位置
    for(int i = 0; i < n; i++) {
        if(cur < i) {
            jump++;
            cur = next;
        }
        if(cur >= n - 1) {
            return jump;
        }
        next = max(next, i + arr[i]);
    }
    
    return jump;
}

int main () {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << minJump(arr);
    
    return 0;
}