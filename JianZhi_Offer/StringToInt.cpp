/* 剑指 Offer - 把字符串转换成整数

 * 将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，
 * 但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。 
 * 数值为0或者字符串不是一个合法的数值则返回0。

 * 输入描述:输入一个字符串,包括数字字母符号,可以为空
 * 输出描述:如果是合法的数值表达则返回该数字，否则返回0 
 */

class Solution {
public:
    int StrToInt(string str) {
        if(str.length() == 0) return 0;
        
        bool isMinus = false;
        int i = 0, res = 0;
        
        if(str[0] == '-'){
            isMinus = true;
            i++;
        }
        else if(str[0] == '+') {
            isMinus = false;
            i++;
        }
        
        for(; i < str.length(); i++) {
            int diff = str[i] - '0';
            if(diff >= 0 && diff <= 9)
                res = res * 10 + diff;
            else
                return 0;
        }
        
        return isMinus ? 0 - res : res;
    }
};