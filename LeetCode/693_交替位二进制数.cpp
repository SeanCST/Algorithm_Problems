class Solution {
public:
    bool hasAlternatingBits(int n) {
        int x = n ^ (n >> 1);
        if(x == INT_MAX) {
            return true;
        } else {
            return (x & (x + 1)) == 0;
        }
    }
};

// class Solution {
// public:
//     bool hasAlternatingBits(int n) {
//         int x = (n & 1) == 1 ? 1 : 0;

//         while(n) {
//             if(n % 2 != x) {
//                 return false;
//             }
//             n >>= 1;
//             x = 1 - x;
//         }

//         return true;
//     }
// };