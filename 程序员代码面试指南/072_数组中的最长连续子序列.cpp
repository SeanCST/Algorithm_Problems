#include <iostream>
#include <vector>
#include <map>
using namespace std;

int merge(map<int, int>& m, int less, int more) {
    int left = less - m[less] + 1;
    int right = more + m[more] - 1;
    int len = right - left + 1;
    m[left] = len;
    m[right] = len;
    
    return len;
}

int longestConsecutive(vector<int> arr) {
    int n = arr.size();
    if(n == 0) {
        return 0;
    }
    
    int res = 1;
    map<int, int> m;
    
    for(int i = 0; i < n; i++) {
        if(m.count(arr[i]) == 0) { // 不考虑重复的数
            m[arr[i]] = 1;
            if(m.count(arr[i] - 1) > 0) {
                res = max(res, merge(m, arr[i] - 1, arr[i]));
            }
            if(m.count(arr[i] + 1) > 0) {
                res = max(res, merge(m, arr[i], arr[i] + 1));
            }
        }
    }
    
    return res;
}

int main () {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << longestConsecutive(arr);
    
    return 0;
}