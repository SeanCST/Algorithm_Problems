class Solution {
    public String longestPalindrome(String s) {
        int len = s.length();
        if (len < 2) {
            return s;
        }
        int maxLen = 1, begin = 0;

        char[] charArr = s.toCharArray();
        for (int i = 0; i < len - 1; i++) {
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < len && charArr[l] == charArr[r]) {
                if (r - l + 1 > maxLen) {
                    maxLen = r - l + 1;
                    begin = l;
                }
                l--;
                r++;
            }

            l = i; 
            r = i + 1;
            while (l >= 0 && r < len && charArr[l] == charArr[r]) {
                if (r - l + 1 > maxLen) {
                    maxLen = r - l + 1;
                    begin = l;
                }
                l--;
                r++;
            }
        }

        return s.substring(begin, begin + maxLen);
    }
}

class Solution {
    public String longestPalindrome(String s) {
        int len = s.length();
        if (len < 2) {
            return s;
        }

        int maxLen = 1, begin = 0;
        boolean[][] dp = new boolean[len][len];
        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
        }

        char[] charArray = s.toCharArray();
        for (int L = 2; L <= len; L++) {
            for (int i = 0; i < len; i++) {
                int j = i + L - 1;
                if (j >= len) {
                    break;
                }

                if (charArray[i] != charArray[j]) {
                    dp[i][j] = false;
                } else {
                    dp[i][j] = j - i < 3 ? true : dp[i + 1][j - 1];
                }

                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }

        return s.substring(begin, begin + maxLen);
    }
}