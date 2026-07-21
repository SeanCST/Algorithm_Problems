class Solution {
    public int maxActiveSectionsAfterTrade(String s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            cnt += s.charAt(i) == '1' ? 1 : 0;
        }

        String str = "1" + s + "1";
        int zeroStart = -1, zeroEnd = -1, oneStart = -1, oneEnd = -1;
        int ans = cnt;
        for (int i = 1; i < str.length(); i++) {
            char c = str.charAt(i);
            if (c == '0') {
                if (zeroStart < 0) {
                    zeroStart = i;
                } else if (str.charAt(i - 1) == '1') {
                    oneEnd = i - 1;
                }
            } else {
                if (str.charAt(i - 1) == '0') {
                    if (oneStart < 0) {
                        oneStart = i;
                    } else {
                        zeroEnd = i - 1;
                        ans = Math.max(ans, cnt + (oneStart - zeroStart) + (zeroEnd - oneEnd));
                        zeroStart = oneEnd + 1;
                        oneStart = i;
                    }
                }
                oneEnd = i;
            }
        }

        return ans;
    }
}