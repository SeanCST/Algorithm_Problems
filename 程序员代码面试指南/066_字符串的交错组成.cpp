#include <iostream>
#include <string>
#include <vector>
using namespace std;

// bool isCross(string s1, string s2, string aim) {
//     int n1 = s1.length(), n2 = s2.length(), n = aim.length();
//     int i = 0, j = 0, k = 0;
//     while((i < n1 || j < n2) && k < n) {
//         if(i < n1 && aim[k] == s1[i]) {
//             i++;
//         } else if(j < n2 && aim[k] == s2[j]) {
//             j++;
//         } else {
//             return false;
//         }
        
//         k++;
//     }
    
//     if(i == n1 && j == n2 && k == n) {
//         return true;
//     } else {
//         return false;
//     }
// }

bool isCross(string s1, string s2, string aim) {
    int n1 = s1.length(), n2 = s2.length(), n = aim.length();
    if(n != n1 + n2) {
        return false;
    }
    // dp[i][j] 表示 aim[i+j-1] 能否被 s1[i-1] 和 s2[j-1] 交错组成
    vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false)); 
    dp[0][0] = true;
    for (int i = 1; i <= n1; i++) {
        if(s1[i - 1] != aim[i - 1]) {
            break;
        }
        dp[i][0] = true;
    }
    for (int j = 1; j <= n2; j++) {
        if(s2[j - 1] != aim[j - 1]) {
            break;
        }
        dp[0][j] = true;
    }
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if((dp[i - 1][j] == true && s1[i - 1] == aim[i + j - 1]) || 
                (dp[i][j - 1] == true && s2[j - 1] == aim[i + j - 1])) {
                    dp[i][j] = true;
                }
        }
    }

    return dp[n1][n2];
}

int main() {
    string str1, str2, aim;
    cin >> str1 >> str2 >> aim;
    
    string res = isCross(str1, str2, aim) ? "YES" : "NO";
    cout << res;
    
    return 0;
}
