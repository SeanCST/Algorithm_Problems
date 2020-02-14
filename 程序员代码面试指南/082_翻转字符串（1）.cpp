#include <iostream>
#include <string>
using namespace std;

void reverse(string& s, int l, int r) {
    while(l < r) {
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++;
        r--;
    }
}

void reverseString(string& s) {
    int n = s.length();
    // reverse(s, 0, n - 1);
    int left = 0, right = 0;
    for(int i = 0; i <= n; i++) {
        if(i == n || s[i] == ' ') {
            right = i - 1;
            reverse(s, left, right);
            left = i + 1;
        }
    }
}

int main() {
    string s;
    getline(cin, s);
    reverseString(s);
    cout << s;
    
    return 0;
}