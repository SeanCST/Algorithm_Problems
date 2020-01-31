#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isValid(string s) {
    int n = s.length();
    if((n & 1) == 0) { // 长度为奇数时才合法
        return false;
    }
    for(int i = 0; i < n; i += 2) {
        if((s[i] != '1') && (s[i] != '0')) {
            return false;
        }
    }
    for(int i = 1; i < n; i += 2) {
        if((s[i] != '^') && (s[i] != '&') && (s[i] != '|')) {
            return false;
        }
    }

    return true;
}

int num(string s, bool desired) {
    int n = s.length();
    if(!isValid(s)) {
        return 0;
    }

    vector<vector<long long> > t(n, vector<long long>(n, 0));
    vector<vector<long long> > f(n, vector<long long>(n, 0));
    t[0][0] = s[0] == '0' ? 0 : 1;
    f[0][0] = s[0] == '0' ? 1 : 0;
    int mod = 1000000007;
    for(int i = 2; i < n; i += 2) {
        t[i][i] = s[i] == '0' ? 0 : 1;
        f[i][i] = s[i] == '0' ? 1 : 0;
        for(int j = i - 2; j >= 0; j -= 2) {
            for(int k = j; k < i; k += 2) {
                if(s[k + 1] == '&') {
                    t[j][i] += t[j][k] * t[k + 2][i];
                    f[j][i] += f[j][k] * t[k + 2][i] + t[j][k] * f[k + 2][i] + f[j][k] * f[k + 2][i];
                    t[j][i] %= mod;
                    f[j][i] %= mod;
                } else if(s[k + 1] == '|') {
                    t[j][i] += f[j][k] * t[k + 2][i] + t[j][k] * f[k + 2][i] + t[j][k] * t[k + 2][i];
                    f[j][i] += f[j][k] * f[k + 2][i];
                    t[j][i] %= mod;
                    f[j][i] %= mod;
                } else {
                    t[j][i] += f[j][k] * t[k + 2][i] + t[j][k] * f[k + 2][i];
                    f[j][i] += f[j][k] * f[k + 2][i] + t[j][k] * t[k + 2][i];
                    t[j][i] %= mod;
                    f[j][i] %= mod;
                }
            }
        }
    }

    return desired ? t[0][n - 1] : f[0][n - 1];
}

int main() {
    string s, desiredStr;
    bool desired;
    cin >> s;
    cin >> desiredStr;
    if(desiredStr == "true") {
        desired = true;
    } else {
        desired = false;
    }
    
    cout << num(s, desired);
    
    return 0;
}