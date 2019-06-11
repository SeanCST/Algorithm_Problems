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