class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        ArrayList<String> res = new ArrayList<>();
        for(String word : words) {
            char[] mapping1 = new char[26];
            char[] mapping2 = new char[26];

            boolean isMatch = true;
            for(int i = 0; i < word.length(); i++) {
                char w = word.charAt(i);
                char p = pattern.charAt(i);
                if(mapping1[w - 'a'] == 0 && mapping2[p - 'a'] == 0) {
                    mapping1[w - 'a'] = p;
                    mapping2[p - 'a'] = w;
                } else if(mapping1[w - 'a'] != p || mapping2[p - 'a'] != w) {
                    isMatch = false;
                    break;
                }
            }

            if(isMatch) {
                res.add(word);
            }
        }

        return res;
    }
}