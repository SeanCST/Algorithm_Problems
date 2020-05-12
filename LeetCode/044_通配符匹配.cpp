class Solution {
public:
    bool isMatch(string s, string p) {
        int m = p.length(), n = s.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // 初始化
        dp[0][0] = true;
        for(int i = 1; i <= m; i++) {
            if(p[i - 1] == '*') {
                dp[i][0] = true;
            } else {
                break;
            }
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(p[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else if(p[i - 1] == '?' || p[i - 1] == s[j - 1]) { 
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[m][n];
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = p.length(), n = s.length();
        if(m == 0 || n == 0) {
            return true;
        }

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n; i++) {
            dp[0][i] = false;
        }

        for(int i = 1; i <= m; i++) {
            if(p[i - 1] == '*') {
                dp[i][0] = dp[i - 1][0];
                for(int j = 1; j <= n; j++) {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            } else if(p[i - 1] == '?') {
                dp[i][0] = false;
                for(int j = 1; j <= n; j++) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            } else {
                dp[i][0] = false;
                for(int j = 1; j <= n; j++) {
                    dp[i][j] = s[j - 1] == p[i - 1] && dp[i - 1][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};