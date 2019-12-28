#include <iostream>
#include <vector>
using namespace std;

bool isPostOrderBST(vector<int> arr, int begin, int end) {
    if(begin >= end) {
        return true;
    }
    int smallerIndex = -1;
    int biggerIndex = end;
    for(int i = begin; i < end; i++) {
        if(arr[end] > arr[i]) {
            smallerIndex = i;
        } else {
            if(biggerIndex == end) {
                biggerIndex = i;
            }
        }
    }
    
    if(smallerIndex == -1 || biggerIndex == end) {
        return isPostOrderBST(arr, begin, end - 1);
    }
    if(smallerIndex != biggerIndex - 1) {
        return false;
    }
    
    return isPostOrderBST(arr, begin, smallerIndex) && 
           isPostOrderBST(arr, biggerIndex, end - 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        arr[i] = x;
    }
    
    if(isPostOrderBST(arr, 0, n - 1)) {
        cout << "true";
    } else {
        cout << "false";
    }
    
    return 0;
}