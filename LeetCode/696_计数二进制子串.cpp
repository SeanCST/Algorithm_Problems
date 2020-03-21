class Solution {
public:
    int countBinarySubstrings(string s) {
        if(s.length() == 0) {
            return 1;
        }
        int ans = 0;
        int last = 0, cur = 1;

        for(int i = 1; i < s.length(); i++) {
            if(s[i] == s[i - 1]) {
                cur++;
            } else {
                last = cur;
                cur = 1;
            }
            if(last >= cur) {
                ans++;
            }
        }

        return ans;
    }
};

// class Solution {
// public:
//     int countBinarySubstrings(string s) {
//         if(s.length() == 0) {
//             return 1;
//         }
//         int ans = 0;
//         int zeroCount = 0, oneCount = 0;

//         for(int i = 0; i < s.length(); i++) {
//             if(s[i] == '0') {
//                 if(i > 0 && s[i - 1] == '1') {
//                     zeroCount = 1;
//                 } else {
//                     zeroCount++;
//                 }
                
//                 if(oneCount >= zeroCount) {
//                     ans++;
//                 } 
//             } else if(s[i] == '1') {
//                 if(i > 0 && s[i - 1] == '0') {
//                     oneCount = 1;
//                 } else {
//                     oneCount++;
//                 }
                
//                 if(zeroCount >= oneCount) {
//                     ans++;
//                 } 
//             }
//         }

//         return ans;
//     }
// };