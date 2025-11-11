
class Solution {
    public int countSegments(String s) {
        int res = 0;
        char[] chars = s.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            if ((i > 0 && chars[i - 1] != ' ' && chars[i] == ' ') 
                || (i == chars.length - 1 && chars[i] != ' ')) {
                res++;
            }
        }

        return res;
    }
}
