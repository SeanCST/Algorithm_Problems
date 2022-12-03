class Solution {
    public int secondHighest(String s) {
        int res = -1;
        int max = -1;
        for(char c : s.toCharArray()) {
            if(c >= '0' && c <= '9') {
                int cur = c - '0';
                if(cur > max) {
                    res = max;
                    max = cur;
                } else if(cur < max && cur > res) {
                    res = cur;
                }
            }
        }

        return res;
    }
}