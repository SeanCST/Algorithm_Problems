#include <iostream>
#include <string>
#include <climits>
using namespace std;

bool isValid(string str) {
    if(str[0] != '-' && (str[0] < '0' || str[0] > '9')) {
        return false;
    }
    if(str[0] == '-' && (str.length() == 1 || str[1] == '0')) {
        return false;
    }
    if(str[0] == '0' && str.length() > 1) {
        return false;
    }
    for(int i = 1; i < str.length(); i++) {
        if(str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    
    return true;
}

int convert(string str) {
    int n = str.length();
    if(n == 0 || !isValid(str)) {
        return 0;
    }
    bool minus = str[0] == '-';
    int res = 0;
    // 因为负数的范围比正数的范围要大，所以先全用负数来表示
    int minq = INT_MIN / 10;
    int minr = INT_MIN % 10;
    for(int i = minus ? 1 : 0; i < n; i++) {
        int cur = '0' - str[i];
        if(res < minq || (res == minq && cur < minr)) {
            return 0;
        }
        res = res * 10 + cur;
    }
    
    if(!minus && res == INT_MIN) {
        return 0;
    } else {
        return minus ? res : -res;
    }
}

int main() {
    string str;
    cin >> str;
    cout << convert(str);
    
    return 0;
}