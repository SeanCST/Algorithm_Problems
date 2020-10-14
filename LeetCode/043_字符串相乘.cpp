class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") {
            return "0";
        }

        int zeroCount = 0;
        string res;
        for(int i = num2.length() - 1; i >= 0; i--) {
            char curDigit = num2[i];
            string resOfMultiplyDigit = multiplyDigit(num1, curDigit, zeroCount++);
            res = add(res, resOfMultiplyDigit);
        }

        return res;
    }

    string multiplyDigit(string num1, char digit, int zeroCount) {
        string res = "";
        int digitNum = digit - '0';
        int carry = 0;
        for(int i = num1.length() - 1; i >= 0; i--) {
            char c = num1[i];
            int mul = (c - '0') * digitNum + carry;
            if(mul >= 10) {
                carry = mul / 10;
                mul = mul % 10;
            } else {
                carry = 0;
            }
            res = to_string(mul) + res;
        }
        if(carry > 0) {
            res = to_string(carry) + res;
        }

        string zeroStr = string(zeroCount, '0');
        res += zeroStr;

        return res;
    }

    string add(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int carry = 0;
        string res = "";

        int n1 = num1.length();
        int n2 = num2.length();
        int i = 0;
        for(; i < n1 && i < n2; i++) {
            int digitSum = (num1[i] - '0') + (num2[i] - '0') + carry;
            if(digitSum >= 10) {
                carry = digitSum / 10;
                digitSum = digitSum % 10;
            } else {
                carry = 0;
            }

            res = res + to_string(digitSum);
        }

        if(n1 < n2) {
            num1 = num2;
            n1 = n2;
        }
        for(; i < n1; i++) {
            int s = (num1[i] - '0') + carry;
            if(s >= 10) {
                carry = s / 10;
                s = s % 10;
            } else {
                carry = 0;
            }
            res = res + to_string(s);
        }
        if(carry > 0) {
            res = res + to_string(carry);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};