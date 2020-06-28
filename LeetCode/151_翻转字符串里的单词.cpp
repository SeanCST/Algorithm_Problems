class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        int i = 0, len = s.length();
        int curBegin = 0;
        for(int i = 0; i < len; i++) {
            if((i == 0 && s[i] != ' ') || (i > 0 && s[i - 1] == ' ' && s[i] != ' ')) {
                curBegin = i;
            }
            
            if(i > 0 && s[i - 1] != ' ' && s[i] == ' ') {
                int curLen = i - curBegin;
                stk.push(s.substr(curBegin, curLen));
            } 
            
            if(i == len - 1 && s[i] != ' ') {
                int curLen = i - curBegin + 1;
                stk.push(s.substr(curBegin, curLen));
            }
        }

        string res;
        bool isFirst = true;
        while(!stk.empty()) {
            string temp = stk.top();
            stk.pop();
            if(!isFirst) {
                res += ' ';
            } else {
                isFirst = false;
            }
            res += temp;
        }

        return res;
    }
};