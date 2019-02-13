class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for(int i = 0; i < s.length(); i++)
        {
            int k = s[i] - 'A' + 1;
            res = res * 26 + k;
        }
        
        return res;
    }
};