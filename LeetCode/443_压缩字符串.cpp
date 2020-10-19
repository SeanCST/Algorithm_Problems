class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if(n == 0 || n == 1) {
            return n;
        }

        int curCount = 1;
        int curIdx = 0;
        char preChar = chars[0];
        for(int i = 1; i <= n; i++) {
            if(i == n || chars[i] != preChar) {
                chars[curIdx++] = preChar;
                if(curCount > 1) {
                    string countStr = to_string(curCount);
                    for(char c : countStr) {
                        chars[curIdx++] = c;
                    }
                    curCount = 1;
                }
                if(i < n) {
                    preChar = chars[i];
                }
            } else if(chars[i] == preChar) {
                curCount++;
            }
        }

        return curIdx;
    }
};