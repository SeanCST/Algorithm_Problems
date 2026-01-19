class Solution {
    public int countSubstrings(String s) {
        int n = s.length(), res = 0;

        for (int i = 0; i < n; i++) {
            res += expand(s, i, i);
            res += expand(s, i, i + 1);
        }

        return res;
    }

    private int expand(String s, int l, int r) {
        int count = 0;
        while (l >= 0 && r < s.length() && s.charAt(l) == s.charAt(r)) {
            count++;
            l--;
            r++;
        }

        return count;
    }
}

// class Solution {
//     public int countSubstrings(String s) {
//         int n = s.length(), res = 0;
//         boolean[] dp = new boolean[n];

//         for (int i = n - 1; i >= 0; i--) {
//             for (int j = n - 1; j >= i; j--) {
//                 if (s.charAt(i) != s.charAt(j)) {
//                     dp[j] = false;
//                 } else {
//                     if (j - i < 2 || dp[j - 1]) {
//                         dp[j] = true;
//                         res++;
//                     } else {
//                         dp[j] = false;
//                     }
//                 }
//             }
//         }

//         return res;
//     }
// }