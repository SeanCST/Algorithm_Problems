class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while(left <= right) {
            while(left < s.length() && !((s[left] <= 'Z' && s[left] >= 'A') || (s[left] <= 'z' && s[left] >= 'a') || (s[left] >= '0' && s[left] <= '9'))) {
                left++;
            }
            
            while(right >= 0 && !((s[right] <= 'Z' && s[right] >= 'A') || (s[right] <= 'z' && s[right] >= 'a') || (s[right] >= '0' && s[right] <= '9'))) {
                right--;
            }
            
            if(left <= right) {
                if(toupper(s[left]) == toupper(s[right])) {
                    left++;
                    right--;
                } else {
                    return false;
                }
            }
        }
        
        return true;
    }
};