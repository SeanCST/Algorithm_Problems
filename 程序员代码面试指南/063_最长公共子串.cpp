#include <iostream>
#include <string>
#include <vector>
using namespace std;

// // 空间复杂度 O(m * n)
// vector<vector<int>> getDp(string s1, string s2) {
//     int m = s1.length();
//     int n = s2.length();
//     vector<vector<int>> dp(m, vector<int>(n, 0));
//     for (int i = 0; i < m; i++) {
//         if (s1[i] == s2[0]) {
//             dp[i][0] = 1;
//         }
//     }
//     for (int i = 0; i < n; i++) {
//         if (s1[0] == s2[i]) {
//             dp[0][i] = 1;
//         }
//     }
//     for (int i = 1; i < m; i++) {
//         for (int j = 1; j < n; j++) {
//             if (s1[i] == s2[j]) {
//                 dp[i][j] = dp[i - 1][j - 1] + 1;
//             }
//         }
//     }
    
//     return dp;
// }

// string getLCST(string str1, string str2) {
//     int m = str1.length();
//     int n = str2.length();
//     if(m == 0 || n == 0) {
//         return "-1";
//     }
//     vector<vector<int>> dp = getDp(str1, str2);
//     int maxLen = 0;
//     int maxI = -1;
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             if(dp[i][j] > maxLen) {
//                 maxLen = dp[i][j];
//                 maxI = i;
//             }
//         }
//     }

//     if(maxI != -1) {
//         return str1.substr(maxI - maxLen + 1, maxLen);
//     }

//     return "-1";
// }

// 空间复杂度 O(1)
string getLCST(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();
    if(m == 0 || n == 0) {
        return "-1";
    } 
    int maxLen = 0; // 记录最大长度
    int maxIndex = -1; // 记录最大长度更新时，子串在 str1 中的结尾位置
    int row = 0; // 斜线开始位置的行
    int col = n - 1; // 斜线开始位置的列

    while (row < m) {
        int i = row;
        int j = col;
        int len = 0;

        while (i < m && j < n) {
            if (str1[i] != str2[j]) {
                len = 0;
            } else {
                len++;
            }
            if (len > maxLen) {
                maxIndex = i;
                maxLen = len;
            }
            i++;
            j++;
        }
        if (col > 0) {
            col--;
        } else {
            row++;
        }
    }
    
    if(maxIndex != -1) {
        return str1.substr(maxIndex - maxLen + 1, maxLen);
    }

    return "-1";
}

int main() {
    string str1, str2;
    cin >> str1;
    cin >> str2;
    
    string lcst = getLCST(str1, str2);
    cout << lcst;
    
    return 0;
}