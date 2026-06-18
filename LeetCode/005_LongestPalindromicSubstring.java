class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        boolean[][] dp = new boolean[n][n];
        int begin = 0, maxLen = 1;

        for (int r = 0; r < n; r++) {
            for (int l = 0; l <=r; l++) {
                if (s.charAt(l) == s.charAt(r)) {
                    if (r - l <= 2 || dp[l + 1][r - 1]) {
                        dp[l][r] = true;

                        int len = r - l + 1;
                        if (len > maxLen) {
                            begin = l;
                            maxLen = len;
                        }
                    }
                }
            }
        }

        return s.substring(begin, begin + maxLen);
    }
}

class Solution {
    public String longestPalindrome(String s) {
        String ans = "";
        for (int i = 0; i < s.length(); i++) {
            String exp1 = expand(s, i, i);
            String exp2 = expand(s, i, i + 1);
            String cur = exp1.length() > exp2.length() ? exp1 : exp2;
            ans = cur.length() > ans.length() ? cur : ans;
        }
        
        return ans;
    }

    private String expand(String s, int l, int r) {
        while (l >= 0 && r < s.length() && s.charAt(l) == s.charAt(r)) {
            l--;
            r++;
        }

        return s.substring(l + 1, r);
    }
}

// class Solution {
//     public String longestPalindrome(String s) {
//         int len = s.length();
//         if (len < 2) {
//             return s;
//         }
//         int maxLen = 1, begin = 0;

//         char[] charArr = s.toCharArray();
//         for (int i = 0; i < len - 1; i++) {
//             int l = i - 1, r = i + 1;
//             while (l >= 0 && r < len && charArr[l] == charArr[r]) {
//                 if (r - l + 1 > maxLen) {
//                     maxLen = r - l + 1;
//                     begin = l;
//                 }
//                 l--;
//                 r++;
//             }

//             l = i; 
//             r = i + 1;
//             while (l >= 0 && r < len && charArr[l] == charArr[r]) {
//                 if (r - l + 1 > maxLen) {
//                     maxLen = r - l + 1;
//                     begin = l;
//                 }
//                 l--;
//                 r++;
//             }
//         }

//         return s.substring(begin, begin + maxLen);
//     }
// }

// class Solution {
//     public String longestPalindrome(String s) {
//         int len = s.length();
//         if (len < 2) {
//             return s;
//         }

//         int maxLen = 1, begin = 0;
//         boolean[][] dp = new boolean[len][len];
//         for (int i = 0; i < len; i++) {
//             dp[i][i] = true;
//         }

//         char[] charArray = s.toCharArray();
//         for (int L = 2; L <= len; L++) {
//             for (int i = 0; i < len; i++) {
//                 int j = i + L - 1;
//                 if (j >= len) {
//                     break;
//                 }

//                 if (charArray[i] != charArray[j]) {
//                     dp[i][j] = false;
//                 } else {
//                     dp[i][j] = j - i < 3 ? true : dp[i + 1][j - 1];
//                 }

//                 if (dp[i][j] && j - i + 1 > maxLen) {
//                     maxLen = j - i + 1;
//                     begin = i;
//                 }
//             }
//         }

//         return s.substring(begin, begin + maxLen);
//     }
// }