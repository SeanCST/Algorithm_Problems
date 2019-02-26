class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.length() - 1;
        while(left < right) {
            while(left <= s.length() - 1 && 
                  (toupper(s[left]) != 'A' 
                  && toupper(s[left]) != 'E' 
                  && toupper(s[left]) != 'I'  
                  && toupper(s[left]) != 'O' 
                  && toupper(s[left]) != 'U'))
                left++;
            
            while(right >= 0 && 
                  (toupper(s[right]) != 'A' 
                  && toupper(s[right]) != 'E' 
                  && toupper(s[right]) != 'I'  
                  && toupper(s[right]) != 'O' 
                  && toupper(s[right]) != 'U'))
                right--;
            
            if(left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        
        return s;
    }
};