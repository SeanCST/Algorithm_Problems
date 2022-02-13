class Solution {
    public int maxNumberOfBalloons(String text) {
        Map<Character, Integer> map = new HashMap<Character, Integer>();

        for(int i = 0; i < text.length(); i++) {
            map.put(text.charAt(i), map.getOrDefault(text.charAt(i), 0) + 1);
        }

        int b = map.getOrDefault('b', 0);
        int a = map.getOrDefault('a', 0);
        int l = map.getOrDefault('l', 0);
        int o = map.getOrDefault('o', 0);
        int n = map.getOrDefault('n', 0);

        int count1 = Math.min(Math.min(b, a), n);
        int count2 = Math.min(l / 2, o / 2);

        return Math.min(count1, count2);
    }
}