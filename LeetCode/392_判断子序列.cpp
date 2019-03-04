class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_len = s.length(), t_len = t.length();
        int s_index = 0, t_index = 0;
        
        while(s_index < s_len && t_index < t_len) {
            if(t[t_index++] == s[s_index]) {
                s_index++;
            } 
        }
        
        return s_index == s_len;
    }
};