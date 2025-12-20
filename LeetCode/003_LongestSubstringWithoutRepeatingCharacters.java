class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> map = new HashMap<>();
        int res = 0, l = 0;
        for (int r = 0; r < s.length(); r++) {
            char c = s.charAt(r);
            if (map.containsKey(c)) {
                l = Math.max(map.get(c), l);
            }
            res = Math.max(res, r - l + 1);
            map.put(c, r + 1);
        }

        return res;
    }
}