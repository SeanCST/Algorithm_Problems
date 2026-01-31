class Solution {
    public int longestSubstring(String s, int k) {
        int[] count = new int[26];
        for (char c : s.toCharArray()) {
            count[c - 'a']++;
        }

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (count[c - 'a'] < k) {
                int l = longestSubstring(s.substring(0, i), k);
                int r = longestSubstring(s.substring(i + 1, s.length()), k);
                return Math.max(l, r);
            }            
        }

        return s.length();
    }
}

// class Solution {
//     public int longestSubstring(String s, int k) {
//         if (s.length() < k) return 0;
//         HashMap<Character, Integer> counter = new HashMap();
//         for (int i = 0; i < s.length(); i++) {
//             counter.put(s.charAt(i), counter.getOrDefault(s.charAt(i), 0) + 1);
//         }
//         for (char c : counter.keySet()) {
//             if (counter.get(c) < k) {
//                 int res = 0;
//                 for (String t : s.split(String.valueOf(c))) {
//                     res = Math.max(res, longestSubstring(t, k));
//                 }
//                 return res;
//             }
//         }
//         return s.length();
//     }
// }
