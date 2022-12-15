class Solution {
    public int getLucky(String s, int k) {
        int res = 0;
        for(char c : s.toCharArray()) {
            int cur = c - 'a' + 1;
            if(cur >= 10) {
                res += cur / 10;
                cur = cur % 10;
            }
            res += cur;
        }
        while(--k > 0) {
            int cur = res;
            res = 0;
            while(cur > 0) {
                res += cur % 10;
                cur /= 10;
            }
        }

        return res;
    }
}