class Solution {
    private static final int L = 10;
    private static final Map<Character, Integer> BIN = new HashMap<>() {{
        put('A', 0);
        put('C', 1);
        put('G', 2);
        put('T', 3);
    }};

    public List<String> findRepeatedDnaSequences(String s) {
        List<String> res = new ArrayList<>();
        if (s.length() < L) {
            return res;
        }

        int x = 0;
        for (int i = 0; i < L - 1; i++) {
            x = (x << 2) | BIN.get(s.charAt(i));
        }

        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i <= s.length() - L; i++) {
            x = ((x << 2) | BIN.get(s.charAt(i + L - 1))) & ((1 << (2 * L)) - 1);
            map.put(x, map.getOrDefault(x, 0) + 1);
            if (map.get(x) == 2) {
                res.add(s.substring(i, i + L));
            }
        }

        return res;
    }
}

// class Solution {
//     public List<String> findRepeatedDnaSequences(String s) {
//         Map<String, Integer> map = new HashMap<>();
//         for (int i = 0; i <= s.length() - 10; i++) {
//             String cur = s.substring(i, i + 10);
//             map.put(cur, map.getOrDefault(cur, 0) + 1);
//         }

//         return map.entrySet().stream()
//             .filter(entry -> entry.getValue() > 1)
//             .map(Map.Entry::getKey)
//             .toList();
//     }
// }