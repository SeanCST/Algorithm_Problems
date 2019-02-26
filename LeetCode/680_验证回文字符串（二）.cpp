class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        bool hasDeletedLeft = false, hasDeletedRight = false;
        int leftDelPos = -1, rightDelPos = -1;
        while(left <= right) {
            if(s[left] == s[right]) {
                left++;
                right--;
            } else {
                if(hasDeletedLeft && hasDeletedRight) // 已经尝试过删除左边和右边不匹配的
                    return false;
                
                if(!hasDeletedLeft) { // 左边没删过，尝试删除左边
                    hasDeletedLeft = true;
                    leftDelPos = left;
                    rightDelPos = right;
                    left++;
                } else if(!hasDeletedRight) { // 右边没删过，尝试删除右边，并返回删除左边时的状态
                    hasDeletedRight = true;
                    left = leftDelPos;
                    right = rightDelPos - 1;
                }
            }
        }
        
        return true;
    }
};