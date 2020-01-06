#include <iostream>
#include <vector>
using namespace std;

int mod = 1e9 + 7;

vector<vector<long>> muliMatrix(vector<vector<long>> m1, vector<vector<long>> m2) {
    vector<vector<long>> res(m1.size(), vector<long>(m2[0].size(), 0));
    for(int i = 0; i < m1.size(); i++) {
        for(int j = 0; j < m2[0].size(); j++) {
            for(int k = 0; k < m1[0].size(); k++) {
                res[i][j] = (res[i][j] + (m1[i][k] * m2[k][j]) % mod) % mod;
            }
        }
    }
    
    return res;
}

vector<vector<long>> matrixPower(vector<vector<long>> m, long p) {
    vector<vector<long>> res(m.size(), vector<long>(m[0].size(), 0));
    // 先把 res 设为单位矩阵
    for(int i = 0; i < res.size(); i++) {
        res[i][i] = 1;
    }
    vector<vector<long>> tmp(m);
    for(; p != 0; p >>= 1) {
        if((p & 1)!= 0) {
            res = muliMatrix(res, tmp);
        }
        tmp = muliMatrix(tmp, tmp);
    }
    
    return res;
}

int main() {
    long n;
    cin >> n;
    
    long fib = 0;
    
    if(n < 1) {
        fib = 0;
    }
    
    if(n <= 2) {
        fib = 1;
    }
    
    vector<vector<long>> base = {{1, 1, 0}, {0, 0, 1}, {1, 0, 0}};
    vector<vector<long>> res = matrixPower(base, n - 3);
    fib = (3 * res[0][0] + 2 * res[1][0] + res[2][0]) % mod;
    
    cout << fib;
        
    return 0;
}