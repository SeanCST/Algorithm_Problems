class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> res = new ArrayList<>();

        int[] count = new int[26];
        for (char c : p.toCharArray()) {
            count[c - 'a']++;
        }

        int left = 0;
        for (int right = 0; right < s.length(); right++) {
            int x = s.charAt(right) - 'a';
            count[x]--;

            while (count[x] < 0) {
                count[s.charAt(left++) - 'a']++;
            }

            if (right - left + 1 == p.length()) {
                res.add(left);
            }
        }

        return res;
    }
}