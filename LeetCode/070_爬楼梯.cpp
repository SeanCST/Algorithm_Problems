class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int last_one = 2, last_two = 1;
        for(int i = 3; i <= n; i++)
        {
            int temp = last_one + last_two;
            last_two = last_one;
            last_one = temp;
        }
        
        return last_one;
    }
};