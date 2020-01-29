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

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(n == 0) {
            return 0;
        }
        int cur = s[n - 1] == '0' ? 0 : 1;
        int next = 1;
        int tmp;
        for(int i = n - 2; i >= 0; i--) {
            if(s[i] == '0') {
                next = cur;
                cur = 0;
            } else {
                tmp = cur;
                if((s[i] - '0') * 10 + s[i + 1] - '0' <= 26) {
                    cur += next;
                }
                next = tmp;
            }
        }

        return cur;
    }
};