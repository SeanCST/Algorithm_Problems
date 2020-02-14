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

void reverseString(string& s, int size) {
    int n = s.length();
    if(size > n) {
        return;
    }
    reverse(s, 0, n - 1);
    reverse(s, 0, n - size - 1);
    reverse(s, n - size, n - 1);
}

int main() {
    int size;
    cin >> size;
    string s;
    cin >> s;
    reverseString(s, size);
    cout << s;
    
    return 0;
}
