class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n <= 1) {
            return n;
        }
        int res = 1;
        set<char> occurances;
        int i = 0, j = 0;
        while(j < n) {
            if(occurances.find(s[j]) == occurances.end()) { // 在本子串中未出现过
                occurances.insert(s[j]);
            } else { // 在本子串中出现过
                res = max(res, j - i);
                while(s[i] != s[j]) {
                    occurances.erase(s[i]);
                    i++;
                }
                i++; // 指向一个新的子串开头
            }
            j++;
        }
        res = max(res, j - i);
        
        return res;
    }
};