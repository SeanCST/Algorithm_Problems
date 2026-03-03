class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();
        for (String str : strs) {
            String tag = generateTag(str);
            map.putIfAbsent(tag, new ArrayList<>());
            map.get(tag).add(str);
        }

        return new ArrayList<List<String>>(map.values());
    }

    private String generateTag(String str) {
        int[] count = new int[26];
        for (char c : str.toCharArray()) {
            count[c - 'a']++;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                sb.append((char)('a' + i));
                sb.append(count[i]);
            }
        }

        return sb.toString();
    }
}