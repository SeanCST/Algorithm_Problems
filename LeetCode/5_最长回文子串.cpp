class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1)
            return s;
        
        int maxLength = 0;
        string res;
        for(int i = 0; i < s.length(); i++) {
            if(i < s.length() - 1 && s[i] == s[i + 1]) { // 以 s[i] 和 s[i + 1] 为中心判断回文
                int k = 0;
                while(i-k >= 0 && i+k+1 < s.length() && s[i - k] == s[i+k+1])
                    k++;
                if(k > maxLength / 2) {
                    maxLength = k * 2;
                    res = s.substr(i-k+1, maxLength);
                }
            } 
            
            if(i > 0 && i < s.length() - 1 && s[i - 1] == s[i + 1]) { // 以 s[i] 为中心判断回文
                int k = 1;
                while(i-k >= 0 && i+k < s.length() && s[i - k] == s[i+k])
                    k++;
                if(k > (maxLength + 1) / 2) {
                    maxLength = k * 2 - 1;
                    res = s.substr(i - k + 1, maxLength);
                }
            }
        }
        
        if(res.length() == 0)
            return s.substr(0, 1);
        
        return res;
    }
};