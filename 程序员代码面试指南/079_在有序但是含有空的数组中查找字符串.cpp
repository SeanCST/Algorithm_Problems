#include <iostream>
#include <string>
#include <vector>
using namespace std;

int getIndex(vector<string>& strs, string str) {
    int n = strs.size();
    if(str == "0" || n == 0) {
        return -1;
    }
    
    int left = 0, right = n - 1;
    int mid = 0;
    int res = -1;
    while(left <= right) {
        mid = left + (right - left) / 2;
        if(strs[mid] != "0" && strs[mid] == str) {
            res = mid;
            right = mid - 1;
        } else if(strs[mid] != "0") {
            if(strs[mid] > str) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            int i = mid;
            while(strs[i] == "0" && --i >= left);
            if(i < left || strs[i] < str) {
                left = mid + 1;
            } else {
                res = strs[i] == str ? i : res;
                right = i - 1;
            }
        }
    }
    
    return res;
}

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    
    vector<string> strs(n, "0");
    for(int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    
    cout << getIndex(strs, str);
    
    return 0;
}