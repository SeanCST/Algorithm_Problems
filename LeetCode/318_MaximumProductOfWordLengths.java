class Solution {
    public int maxProduct(String[] words) {
        int n = words.length;

        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (char c : words[i].toCharArray()) {
                int k = c - 'a';
                mask |= 1 << k;
            }            
            if (words[i].length() > map.getOrDefault(mask, 0)) {
                map.put(mask, words[i].length());
            }
        }

        int res = 0;
        for (int mask1 : map.keySet()) {
            for (int mask2 : map.keySet()) {
                if ((mask1 & mask2) == 0) {
                    res = Math.max(res, map.get(mask1) * map.get(mask2));
                }
            }
        }

        return res;
    }
}