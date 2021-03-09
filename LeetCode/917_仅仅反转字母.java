class Solution {
    public String reverseOnlyLetters(String S) {
        char[] chars = S.toCharArray();
        int l = 0, r = chars.length - 1;
        while(l < r) {
            while(l < r && !isEnglishLetter(chars[l])) {
                l++;
            }
            while(l < r && !isEnglishLetter(chars[r])) {
                r--;
            }

            char temp = chars[l];
            chars[l] = chars[r];
            chars[r] = temp;
            l++;
            r--;
        }

        return new String(chars);
    }

    private boolean isEnglishLetter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
}