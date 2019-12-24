class Solution {
public:
    string intToRoman(int num) {
        string res;
        map<int, char> m = {
            {1, 'I'},
            {5, 'V'},
            {10, 'X'},
            {50, 'L'},
            {100, 'C'},
            {500, 'D'},
            {1000, 'M'}
        };
        int thousand = num / 1000;
        if(thousand > 0) {
            for(int i = 0; i < thousand; i++) {
                res += m[1000];
            }
            num -=  1000 * thousand;
        }
        
        int hundred = num / 100;
        if(hundred > 0) {
            if(hundred == 4) {
                res += m[100];
                res += m[500];
            } else if(hundred == 9) {
                res += m[100];
                res += m[1000];
            } else if(hundred >= 5) {
                res += m[500];
                for(int i = 5; i < hundred; i++) {
                    res += m[100];
                }
            } else {
                for(int i = 0; i < hundred; i++) {
                    res += m[100];
                }
            }
            num -=  100 * hundred;
        }
        
        int ten = num / 10;
        if(ten > 0) {
            if(ten == 4) {
                res += m[10];
                res += m[50];
            } else if(ten == 9) {
                res += m[10];
                res += m[100];
            } else if(ten >= 5) {
                res += m[50];
                for(int i = 5; i < ten; i++) {
                    res += m[10];
                }
            } else {
                for(int i = 0; i < ten; i++) {
                    res += m[10];
                }
            }
            num -=  10 * ten;
        }
        
        if(num > 0) {
            if(num == 4) {
                res += m[1];
                res += m[5];
            } else if(num == 9) {
                res += m[1];
                res += m[10];
            } else if(num >= 5) {
                res += m[5];
                for(int i = 5; i < num; i++) {
                    res += m[1];
                }
            } else {
                for(int i = 0; i < num; i++) {
                    res += m[1];
                }
            }
        }
        
        return res;
    }
};