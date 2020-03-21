class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        int reverseNumber = 0;
        int number = x;
        int maxDivideTen = INT_MAX / 10;
        while(number) {
            if(reverseNumber > maxDivideTen 
               || (reverseNumber == maxDivideTen && number % 10 > INT_MAX % 10)) {
                return false;
            } 
            reverseNumber = reverseNumber * 10 + number % 10;
            number /= 10;
        }

        return reverseNumber == x;
    }

    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }

        string xStr = to_string(x);
        int l = 0, r = xStr.length() - 1;
        while(l < r) {
            if(xStr[l] != xStr[r]) {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        if(x == 0) return true;
        if(x < 0 || x % 10 == 0) return false;
        
        int right = 0;
        
        // 翻转右半部分，完成后 x 为左半部分，right 为右半部分
        while(x > right) {
            right = right * 10 + x % 10;
            x = x / 10;
        }
        
        return x == right || x == right / 10;
    }
};