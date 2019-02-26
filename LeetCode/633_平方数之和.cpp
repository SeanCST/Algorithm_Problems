class Solution {
public:
    bool judgeSquareSum(int c) {
        int left = 0;
        
        // 先找到 sqrt(c)
        int right = (int)sqrt(c); // 向下取整
        
        while(left <= right) {
            int remained = c - right * right;
            int leftPow = left * left;
            if(remained == leftPow) {
                return true;
            } else if (remained > leftPow){
                left++;
            } else {
                right--;
            }
        }
        return false;
    }
};