#include <iostream>
#include <string>
using namespace std;

string statistics(string str) {
    int n = str.length();
    if(n == 0) {
        return str;
    }
    string res;
    char c = str[0];
    int count = 1;
    for(int i = 1; i <= n; i++) {
        if(i == n || str[i] != c) {
            res = res + c + '_' + to_string(count);
            if(i < n) {
                c = str[i];
                res += '_';
            } 
            count = 1;
        } else {
            count++;
        }
    }
    
    return res;
}

int main() {
    string str;
    cin >> str;
    cout << statistics(str);
    
    return 0;
}