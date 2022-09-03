class Solution {
    public int isPrefixOfWord(String sentence, String searchWord) {
        String[] words = sentence.split(" ");
        int len = searchWord.length();
        for (int i = 0; i < words.length; i++) {
            if(len <= words[i].length() 
                && searchWord.equals(words[i].substring(0, len))) {
                    return i + 1;
                }
            // if(words[i].startsWith(searchWord)) {
            //     return i + 1;
            // }
        }

        return -1;
    }
}