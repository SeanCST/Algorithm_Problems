class Solution {
    private static final Map<Character, Integer> ROMAN_MAP = Map.of(
        'I', 1,
        'V', 5,
        'X', 10,
        'L', 50,
        'C', 100,
        'D', 500,
        'M', 1000
    );
    public int romanToInt(String s) {
        int ans = 0, len = s.length();
        for (int i = 0; i < len; i++) {
            int value = ROMAN_MAP.get(s.charAt(i));
            if (i + 1 < len && value < ROMAN_MAP.get(s.charAt(i + 1))) {
                ans -= value;
            } else {
                ans += value;
            }
        }

        return ans;
    }
}