class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        Map<String, Integer> countMap = new HashMap<>();
        for (String word : words) {
            countMap.put(word, countMap.getOrDefault(word, 0) + 1);
        }
        int wordLen = words[0].length(), count = words.length;
        int totalLen = wordLen * count;

        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < wordLen; i++) {
            int l = i, r = i, matched = 0;
            Map<String, Integer> windowMap = new HashMap<>();
            while (r + wordLen <= s.length()) {
                String cur = s.substring(r, r + wordLen);
                r += wordLen;

                if (!countMap.containsKey(cur)) {
                    windowMap.clear();
                    matched = 0;
                    l = r;
                    continue;
                }

                windowMap.put(cur, windowMap.getOrDefault(cur, 0) + 1);
                matched++;

                while (windowMap.get(cur) > countMap.get(cur)) {
                    String lw = s.substring(l, l + wordLen);
                    windowMap.put(lw, windowMap.get(lw) - 1);
                    l += wordLen;
                    matched--;
                }

                if (count == matched) {
                    res.add(l);
                }
            }
        }

        return res;
    }
}