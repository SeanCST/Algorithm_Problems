class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        if(strs.size() == 0) {
            return 0;
        }

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(string str : strs) {
            int zeros = 0, ones = 0;
            for(char c : str) {
                if(c == '0') {
                    zeros++;
                } else {
                    ones++;
                }
            }

            for(int i = m; i >= zeros; i--) {
                for(int j = n; j >= ones; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }

        return dp[m][n];
    }
};