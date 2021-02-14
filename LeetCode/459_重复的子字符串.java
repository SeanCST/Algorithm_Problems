class Solution {
    public boolean repeatedSubstringPattern(String s) {
        String str = s + s;
        return str.substring(1, str.length() - 1).contains(s);

        // 假设母串 S 由子串 a+b 组成，则 (S+S)=a+b+a+b，掐头去尾，则开头的 a 和最后的 b 无法匹配，
        // 相当于 (S+S)[1:-1] = c+b+a+d ，其中 c!=a, d!=b，如果 a+b 在其中出现，则必然有 a=b

    }
}