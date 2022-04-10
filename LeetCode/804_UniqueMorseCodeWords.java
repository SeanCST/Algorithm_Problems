class Solution {
    private static String[] map = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

    public int uniqueMorseRepresentations(String[] words) {
        HashSet<String> set = new HashSet<>();

        for(String word : words) {
            String cur = "";
            for(int i = 0; i < word.length(); i++) {
                cur += map[word.charAt(i) - 'a'];
            }

            set.add(cur);
        }

        return set.size();
    }
}