class Solution {
    public String longestWord(String[] words) {
        Arrays.sort(words);

        Set<String> set = new HashSet<>();
        String res = "";

        for(String s : words) {
            int len = s.length();
            if(len == 1 || set.contains(s.substring(0, len - 1))) {
                res = len > res.length() ? s : res;
                set.add(s);
            }
        }

        return res;
    }
}