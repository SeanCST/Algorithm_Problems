class Solution {
    public String minWindow(String s, String t) {
        int[] tFreq = new int[128];
        int[] windowFreq = new int[128];
        int left = 0, right = 0, start = 0, minLength = Integer.MAX_VALUE, required = 0, valid = 0;
        for (char c : t.toCharArray()) {
            tFreq[c]++;
            if (tFreq[c] == 1) {
                required++;
            }
        }

        while (right < s.length()) {
            char c = s.charAt(right);
            right++;

            if (tFreq[c] > 0) {
                windowFreq[c]++;
                if (tFreq[c] == windowFreq[c]) {
                    valid++;
                }
            }

            while (valid == required) {
                if (right - left < minLength) {
                    start = left;
                    minLength = right - left;
                }
                char d = s.charAt(left);
                left++;
                if (tFreq[d] > 0) {
                    if (tFreq[d] == windowFreq[d]) {
                        valid--;
                    }
                    windowFreq[d]--;
                }
            }
        }
        
        return minLength == Integer.MAX_VALUE ? "" : s.substring(start, start + minLength);
    }

}