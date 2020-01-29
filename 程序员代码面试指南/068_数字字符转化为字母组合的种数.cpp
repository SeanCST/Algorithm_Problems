#include <iostream>
#include <string>
using namespace std;

// int process(string s, int i) {
//     if(i == s.length()) {
//         return 1;
//     }
//     if(s[i] == '0') {
//         return 0;
//     }
//     int res = process(s, i + 1);
//     if(i + 1 < s.length() && (s[i] - '0') * 10 + (s[i + 1] - '0') <= 26) {
//         res += process(s, i + 2);
//     }
    
//     return res;
// }

// int count(string s) {
//     int n = s.length();
//     if(n == 0) {
//         return 0;
//     }
    
//     return process(s, 0);
// }

int count(string s) {
    int n = s.length();
    if(n == 0) {
        return 0;
    }
    int cur = s[n - 1] == '0' ? 0 : 1;
    int next = 1;
    int tmp = 0;
    int mod = 1000000007;
    for(int i = n - 2; i >= 0; i--) {
        if(s[i] == '0') {
            next = cur;
            cur = 0;
        } else {
            tmp = cur;
            if ((s[i] - '0') * 10 + (s[i + 1] - '0') <= 26) {
                cur = (cur + next) % mod;
            }
            next = tmp;
        }
    }

    return cur;
}

int main() {
    string s;
    cin >> s;
    
    cout << count(s);
    
    return 0;
}