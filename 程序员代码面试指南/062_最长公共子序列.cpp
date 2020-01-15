#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum direction {
    upDirection,
    leftDirection,
    upLeftDirection
};

// vector<vector<direction>> getPath(string s1, string s2) {
//     int m = s1.length();
//     int n = s2.length();
//     vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//     vector<vector<direction>> path(m + 1, vector<direction>(n + 1, upDirection));
//     for(int i = 1; i <= m; i++) {
//         // if(i == 1) {
//         //     cout << "\t";
//         //     for (int j = 1; j <= n; j++) {
//         //         cout << s2[j - 1] << "\t";
//         //     }
//         //     cout << endl;
//         // }
//         for (int j = 1; j <= n; j++) {
//             // if(j == 1) {
//             //     cout << s1[i - 1] << "\t";
//             // }
//             if (s1[i - 1] == s2[j - 1]) {
//                 dp[i][j] = dp[i - 1][j - 1] + 1;
//                 path[i][j] = upLeftDirection;
//                 // cout << "\\" << dp[i][j] << "\t";
//             } else if (dp[i - 1][j] >= dp[i][j - 1]) {
//                 dp[i][j] = dp[i - 1][j];
//                 path[i][j] = upDirection;
//                 // cout << "|" << dp[i][j] << "\t";
//             } else {
//                 dp[i][j] = dp[i][j - 1];
//                 path[i][j] = leftDirection;
//                 // cout << "--" << dp[i][j] << "\t";
//             }
//         }
//         // cout << endl;
//     }

//     return path;
// }

// string getLCS(string s1, string s2) {
//     int m = s1.length();
//     int n = s2.length();
//     string lcs;
//     if(m == 0 || n == 0) {
//         return lcs;
//     }

//     vector<vector<direction>> path = getPath(s1, s2);
//     while(m > 0 && n > 0) {
//         if(path[m][n] == upLeftDirection) {
//             m--;
//             n--;
//             lcs = s1.substr(m, 1) + lcs;
//         } else if (path[m][n] == upDirection) {
//             m--;
//         } else {
//             n--;
//         }
//     }

//     return lcs;
// }

vector<vector<int>> getDp(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // vector<vector<direction>> path(m + 1, vector<direction>(n + 1, upDirection));
    for(int i = 1; i <= m; i++) {
        // if(i == 1) {
        //     cout << "\t";
        //     for (int j = 1; j <= n; j++) {
        //         cout << s2[j - 1] << "\t";
        //     }
        //     cout << endl;
        // }
        for (int j = 1; j <= n; j++) {
            // if(j == 1) {
            //     cout << s1[i - 1] << "\t";
            // }
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                // path[i][j] = upLeftDirection;
                // cout << "\\" << dp[i][j] << "\t";
            } else if (dp[i - 1][j] >= dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j];
                // path[i][j] = upDirection;
                // cout << "|" << dp[i][j] << "\t";
            } else {
                dp[i][j] = dp[i][j - 1];
                // path[i][j] = leftDirection;
                // cout << "--" << dp[i][j] << "\t";
            }
        }
        // cout << endl;
    }

    return dp;
}

string getLCS(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    if(m == 0 || n == 0) {
        return "";
    }

    vector<vector<int>> dp = getDp(s1, s2);
    string lcs(dp[m][n], ' ');
    int index = dp[m][n] - 1;
    while(index >= 0) {
        if(m > 0 && dp[m][n] == dp[m - 1][n]) {
            m--;
        } else if (n > 0 && dp[m][n] == dp[m][n - 1]) {
            n--;
        } else {
            lcs[index--] = s1[m - 1];
            m--;
            n--;
        }
    }

    return lcs;
}

int main() {
    string str1, str2;
    cin >> str1;
    cin >> str2;
    
    string lcs = getLCS(str1, str2);
    cout << lcs;
    
    return 0;
}