class Solution {
public:
    int countBinarySubstrings(string s) {
        int cnt = 0;
        int last = 0, cur = 1;
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == s[i - 1]) {
                cur++; // cur 记录当前连续 0 或 1 的个数
            } else {
                last = cur; // last 记录之前连续 0 或 1 的个数
                cur = 1;
            }
            
            // !!!
            if(last >= cur)
                cnt++;
        }
        
        return cnt;
    }
};