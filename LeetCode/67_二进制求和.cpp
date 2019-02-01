class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.length() - 1, j = b.length() - 1;
        int carry = 0;
        int cur = 0; // 当前位计算结果
        while(i >= 0 && j >= 0){
            if (a[i] == '1' && b[j] == '1') { // 两个都为1
                if (carry == 1) {
                    cur = 1;
                } else {
                    cur = 0;
                    carry = 1;
                }
            } else if (a[i] == '1' || b[j] == '1') { // 有一个为1，有一个为0
                if (carry == 1) {
                    cur = 0;
                } else {
                    cur = 1;
                }
            } else { // 两个都为0
                if (carry == 1) {
                    cur = 1;
                    carry = 0;
                } else {
                    cur = 0;
                }
            }

            // 字符串拼接
            res = to_string(cur) + res;
            i--;
            j--;
        }
        
        while(i >= 0) {
            if (carry == 1) {
                if (a[i] == '1') {
                    cur = 0;
                } else {
                    cur = 1;
                    carry = 0;
                }
            } else {
                if (a[i] == '1') {
                    cur = 1;
                } else {
                    cur = 0;
                }
            }
            res = to_string(cur) + res;
            i--;
        }
        
        while(j >= 0) {
            if (carry == 1) {
                if (b[j] == '1') {
                    cur = 0;
                } else {
                    cur = 1;
                    carry = 0;
                }
            } else {
                if (b[j] == '1') {
                    cur = 1;
                } else {
                    cur = 0;
                }
            }
            res = to_string(cur) + res;
            j--;
        }

        if (carry == 1) {
            res = to_string(1) + res;
        }
        

        return res;
    }
};