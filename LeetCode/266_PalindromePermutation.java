class Solution {
    public boolean canPermutePalindrome(String s) {
        Map<Character, Integer> map = new HashMap<>();

        for (char c : s.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }

        boolean singleAppeared = false;
        for (Map.Entry<Character, Integer> entry : map.entrySet()) {
            if (entry.getValue() %2 == 1) {
                if (singleAppeared) {
                    return false;
                }
                singleAppeared = true;
            }
        }

        return true;
    }
}