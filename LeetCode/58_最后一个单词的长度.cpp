class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        reverse(s.begin(), s.end());
        for(int i = 0; i < s.length(); i++)
        {
            if (res == 0 && s[i] == ' ') { // 以空格开头
                continue;
            } else // 遇到单词
            {
                if (s[i] !=  ' ') {
                    res++;
                }
                else {
                    return res;
                }
            }
        }

        return res;
    }
};