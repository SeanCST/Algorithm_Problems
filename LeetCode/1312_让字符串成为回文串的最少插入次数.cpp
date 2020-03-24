// 动态规划
class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        if(n == 0) {
            return 0;
        }
        // memo[i][j] 表示 s[i...j] 变成回文所需要的最小操作数
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                }
            }
        }

        return dp[0][n - 1];
    }

};

// 递归 + 记忆
class Solution {
public:
    int minInsertions(string s) {
        int len = s.length();
        if(len == 0) {
            return 0;
        }
        // memo[i][j] 表示 s[i...j] 变成回文所需要的最小操作数
        vector<vector<int>> memo(len, vector<int>(len, -1));
        
        process(s, 0, len - 1, memo);

        return memo[0][len - 1];
    }

    void process(string& s, int l, int r, vector<vector<int>>& memo) {
        if(memo[l][r] != -1) {
            return;
        }
        if(l >= r) {
            memo[l][r] = 0;
            return;
        }
        
        if(s[l] == s[r]) {
            process(s, l + 1, r - 1, memo);
            memo[l][r] = memo[l + 1][r - 1];
        } else {
            process(s, l + 1, r, memo);
            process(s, l, r - 1, memo);
            memo[l][r] = min(memo[l + 1][r], memo[l][r - 1]) + 1;
        }
    }
};