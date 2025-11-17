class Solution {
    public String licenseKeyFormatting(String s, int k) {
        StringBuilder sb1 = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (c != '-') {
                if (c >= 'a' && c <= 'z') {
                    sb1.append((char) (c - 32));
                } else {
                    sb1.append(c);
                }
            }
        }        

        String s1 = sb1.toString();
        int extra = s1.length() % k;
        StringBuilder sb2 = new StringBuilder();
        sb2.append(s1.substring(0, extra));
        for(int i = 0; i < s1.length() / k; i++) {
            if(sb2.length() > 0) {
                sb2.append('-');
            }
            sb2.append(s1.substring(extra + i * k, extra + (i + 1) * k));
        }

        return sb2.toString();
    }
}