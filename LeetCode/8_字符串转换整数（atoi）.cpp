// 未能 AC，但是在编译器上跑没有错误

class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        int k = 0;
        bool minus = false;
        while(k < str.length() && str[k] == ' ') // 跳过空格
            k++;
        if(k < str.length()) { // 判断正负
            if(str[k] == '-') {
                minus = true;
                k++;  
            } else if(str[k] == '+') 
                k++;  
        }
        while(k < str.length()) {
            if(str[k] >= '0' && str[k] <= '9') { // 转换成 int
                // 判断是否超出最大或最小范围
                if(INT_MAX / 10 < res) 
                    if(minus)
                        return INT_MIN;
                    else
                        return INT_MAX;
                res += res * 10 + str[k] - '0';
            } else if(k > 0) { // 截止于上一个数字
                break;
            } else if(k == 0) { // 第一个非空字符不是数字或正负号
                return 0;
            }
            k++;
        }
        
        if(minus)
            res = 0 - res;
        
        return res;
    }
};