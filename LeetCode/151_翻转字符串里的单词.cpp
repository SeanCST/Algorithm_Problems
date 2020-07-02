// C

void reverse(char *s, int curLen) {
    int left = 0, right = curLen - 1;
    while(left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

char * reverseWords(char * s){
    int i = 0;
    for(int j = 0; s[j] != '\0'; j++) {
        if((s[j] != ' ') || (i > 0 && s[j] == ' ' && s[j - 1] != ' ')) {
            s[i++] = s[j];
        }
    }
    int len;
    if(i >= 1 && s[i - 1] == ' ') {
        s[i - 1] = '\0';
        len = i - 1;
    } else {
        s[i] = '\0';
        len = i;
    }

    reverse(s, len);

    int curLeft = 0, curLen = 0;
    char *cur = s;
    for(i = 0; i < len; i++) {
        if(i + 1 == len || s[i + 1] == ' ') {
            curLen = i - curLeft + 1;
            reverse(cur, curLen);
            curLeft = i + 2;
            if(i + 1 < len) {
                cur += curLen + 1;
            }
        }
    }

    return s;
}


// CPP

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