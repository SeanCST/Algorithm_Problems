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