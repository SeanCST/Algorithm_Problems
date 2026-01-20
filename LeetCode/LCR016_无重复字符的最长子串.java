class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> set = new HashSet<>();
        int res = 0, l = 0;

        for (int r = 0; r < s.length(); r++) {
            char c = s.charAt(r);
            while (set.contains(c)) {
                set.remove(s.charAt(l++));
            }
            set.add(c);

            res = Math.max(res, r - l + 1);
        }

        return res;
    }
}

// class Solution {
//     public int lengthOfLongestSubstring(String s) {
//         Map<Character, Integer> map = new HashMap<>();
//         int res = 0, l = 0;

//         for (int r = 0; r < s.length(); r++) {
//             char c = s.charAt(r);
//             if (map.containsKey(c)) {
//                 l = Math.max(l, map.get(c));
//             } 

//             map.put(c, r + 1);
//             res = Math.max(res, r - l + 1);
//         }

//         return res;
//     }
// }