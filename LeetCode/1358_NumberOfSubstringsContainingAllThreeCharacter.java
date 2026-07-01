class Solution {
    public int numberOfSubstrings(String s) {
        int[] cnt = new int[3];
        int l = 0, r = 0, ans = 0, meet = 0, n = s.length();
        while (r < n) {
            int cur = s.charAt(r) - 'a';
            if (++cnt[cur] == 1) {
                meet++;
            }

            while (meet == 3) {
                ans += n - r;
                int discard = s.charAt(l++) - 'a';
                if (--cnt[discard] == 0) {
                    meet--;
                }
            }

            r++;
        }

        return ans;
    }
}