class Solution {
    public boolean backspaceCompare(String S, String T) {
        String str1 = backspaceResult(S);
        String str2 = backspaceResult(T);

        return str1.equals(str2);
    }

    private String backspaceResult(String S) {
        String res = "";
        char[] charArray = S.toCharArray();
        for(char c : charArray) {
            if(c != '#') {
                res += c;
            } else {
                int len = res.length();
                if(len > 0) {
                    res = res.substring(0, len - 1);
                }
            }
        }

        return res;
    }
}