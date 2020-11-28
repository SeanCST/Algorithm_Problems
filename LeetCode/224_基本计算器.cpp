class Solution {
public:
    int calculate(string s) {
        stack<int> numStk;
        int res = 0;
        int sign = 1;
        int length = s.length();

        for(int i = 0; i < length; i++) {
            char ch = s[i];
            if(isdigit(ch)) {
                int curNum = ch - '0';
                while(i + 1 < length && isdigit(s[i + 1])) {
                    curNum = curNum * 10 + (s[++i] - '0');
                }
                res = res + sign * curNum;
            } else if(ch == '+') {
                sign = 1;
            } else if(ch == '-') {
                sign = -1;
            } else if(ch == '(') {
                numStk.push(res);
                res = 0;
                numStk.push(sign);
                sign = 1;
            } else if(ch == ')') {
                res = numStk.top() * res;
                numStk.pop();
                res = numStk.top() + res;
                numStk.pop();
            }
        }

        return res;
    }
};