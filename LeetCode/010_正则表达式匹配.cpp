class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length(), pLen = p.length();

        vector<vector<bool>> dp(sLen + 1, vector<bool>(pLen + 1, false));
        dp[0][0] = true;

        for(int i = 0; i <= sLen; i++) {
            for(int j = 1; j <= pLen; j++) {
                if(p[j - 1] == '*') {
                    if(j - 2 < 0 || p[j - 2] == '*') {
                        return false;
                    } else {
                        dp[i][j] = dp[i][j - 2] || (i > 0 && ((s[i - 1] == p[j - 2]) || (p[j - 2] == '.')) && dp[i - 1][j]);
                    }
                } else {
                    dp[i][j] = i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.') && dp[i - 1][j - 1];
                }
            }
        }

        return dp[sLen][pLen];
    }
};