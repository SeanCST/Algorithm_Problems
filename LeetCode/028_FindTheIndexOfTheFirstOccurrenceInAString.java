class Solution {
    public int strStr(String haystack, String needle) {
        int m = haystack.length(), n = needle.length();
        for (int i = 0; i <= m - n; i++) {
            int a = i, b = 0;
            while (b < n && haystack.charAt(a) == needle.charAt(b)) {
                a++;
                b++;
            }

            if (b == n) {
                return i;
            }
        }

        return -1;
    }
}