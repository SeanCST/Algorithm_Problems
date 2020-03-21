class Solution {
private:
    int cnt = 0;
public:
    int countSubstrings(string s) {
        for(int i = 0; i < s.length(); i++) {
            extendSubstring(s, i, i); // 奇数长度
            extendSubstring(s, i, i + 1); // 偶数长度
        }
        return cnt;
    }
    
    void extendSubstring(string s, int start, int end) {
        while(start >= 0 && end < s.length() && s[start] == s[end]) {
            start--;
            end++;
            
            cnt++;
        }
    }
};
class Solution {
public:
    int countSubstrings(string s) {
        // dp[j]表示从j位置到当前遍历到的字符位置i是否为回文字符串
        vector<bool> dp(s.size(), false);

        int res = 0;
        for(int i = 0; i < s.size(); i++){
            dp[i] = true;
            res++;
            for(int j = 0; j < i; j++){
                if(s[j] == s[i] && dp[j + 1]) {
                    dp[j] = true;
                    res++;
                } else {
                    dp[j] = false;
                }
            }
        }
        return res;
    }
};