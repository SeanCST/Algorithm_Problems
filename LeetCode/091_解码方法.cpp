class Solution {
public:
    int numDecodings(string s) {
        if(s.empty())   
            return 0;
        vector<int> dp(s.size(), 0);
        
        for(int i = 0; i < s.size(); ++i) {
            /* 当前一位可以解码成功 */
            if(s[i] != '0')
                dp[i] += (i == 0) ? 1 : dp[i - 1];
            /* 当前一位和上一位组合起来可以解码成功 */
            if(i > 0 && s[i - 1] != '0' && ((s[i - 1] - '0') * 10 + (s[i] - '0') <= 26))
                dp[i] += (i == 1) ? 1 : dp[i - 2];
        }
        return dp[s.size() - 1];
    }
};